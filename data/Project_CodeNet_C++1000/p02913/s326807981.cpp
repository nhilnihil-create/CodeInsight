#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <iomanip>
#include <cassert>
#include <random>

#line 1 "lib/rolling_hash.hpp"



#include <vector>
#include <string>
#include <utility>
#line 1 "lib/random_number_generator.hpp"



#include <random>
#include <chrono>

class RandomNumberGenerator {
public:
    RandomNumberGenerator()
        : seed(std::chrono::steady_clock::now().time_since_epoch().count())
        , mt(seed) {}

    unsigned long long operator()() { return mt(); }

    // Generate a random integer in a range [lo, hi).
    unsigned long long operator()(
        unsigned long long lo, unsigned long long hi = -1) {

        if (hi == -1) {
            hi = lo;
            lo = 0;
        }
        std::uniform_int_distribution<unsigned long long> dist(lo, hi - 1);
        return dist(mt);
    }

    void set_seed(int s) { seed = s; mt = decltype(mt)(seed); }
    long long get_seed() const { return seed; }

private:
    long long seed;
    std::mt19937_64 mt;
};


#line 8 "lib/rolling_hash.hpp"

class RollingHash {
public:
    RollingHash(const std::string &s, unsigned long long base = -1)
        : base(base != -1 ? base : rng(1ULL << 12, mod))
        , base_p(s.size() + 1)
        , chash(s.size() + 1) {

        build(s);
    }

    // Hash a substring corresponding to a range [left, right).
    unsigned long long hash(int left, int right) {
        unsigned long long ret = chash[right] + mod
            - multiply(chash[left], base_p[right - left]);
        if (ret >= mod) ret -= mod;
        return ret;
    }

    unsigned long long get_base() { return base; }

private:
    static constexpr unsigned long long mod = (1ULL << 61) - 1;
    RandomNumberGenerator rng;

    const unsigned long long base;
    std::vector<unsigned long long> base_p;
    std::vector<unsigned long long> chash;

    unsigned long long multiply(unsigned long long a, unsigned long long b) {
        static constexpr unsigned long long M30 = (1ULL << 30) - 1;
        static constexpr unsigned long long M31 = (1ULL << 31) - 1;
        unsigned long long
            au = a >> 31, ad = a & M31, bu = b >> 31, bd = b & M31,
            m = ad * bu + au * bd, mu = m >> 30, md = m & M30;
        return (2 * au * bu + mu + (md << 31) + ad * bd) % mod;
    }

    void build(const std::string &s) {
        int n = s.size();
        base_p[0] = 1;
        for (int i = 0; i < n; i++) {
            chash[i + 1] = (multiply(chash[i], base) + s[i]) % mod;
            base_p[i + 1] = multiply(base_p[i], base);
        }
    }
};

class DoubleRollingHash {
public:
    DoubleRollingHash(const std::string &s,
        unsigned long long basel = -1, unsigned long long baser = -1)
        : hashl(s, basel), hashr(s, baser) {}

    std::pair<unsigned long long, unsigned long long>
        hash(int left, int right) {
        return { hashl.hash(left, right), hashr.hash(left, right) };
    }

    std::pair<unsigned long long, unsigned long long>
        get_base() { return { hashl.get_base(), hashr.get_base() }; }

private:
    RollingHash hashl, hashr;
};


int main() {
    int n; std::string s;
    std::cin >> n >> s;
    DoubleRollingHash rh(s);
    auto check = [&](int len) {
        std::set<decltype(rh.hash(0, 0))> st;
        for (int i = n - 2 * len; i >= 0; i--) {
            st.insert(rh.hash(i + len, i + 2 * len));
            if (st.count(rh.hash(i, i + len))) return true;
        }
        return false;
    };
    int lo = 0, hi = n + 1;
    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    std::cout << lo << std::endl;
    return 0;
}