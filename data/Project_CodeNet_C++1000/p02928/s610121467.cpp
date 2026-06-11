#include <iostream>
#include <vector>
constexpr int MOD = 1'000'000'007; //'

/**
 * T: int, long, long long, ModInt
 * std::stringを使いたい場合は全部int等に変換すること
 */
template <typename T>
class BIT {
    // 1-indexed
    std::vector<T> data;
    std::size_t size;

   public:
    BIT(const std::size_t &n, const T &value = 0) {
        data.assign(n + 1UL, value);
        size = n;
    }

    // add value to idx-th
    void add(const std::size_t &idx, const T &value = 1) {
        for (std::size_t i = idx; i <= size; i += i & (~i + 1UL)) {  // LSB
            data.at(i) += value;
        }
    }

    // sum of [1, idx]
    T sum(const std::size_t &idx) {
        T res = 0;
        for (std::size_t i = idx; i > 0UL; i -= i & (~i + 1UL)) {  // LSB
            T d = data.at(i);                                      // cast
            res += d;
        }
        return res;
    }

    // sum of [first, last]
    T sum(const std::size_t &first, const std::size_t &last) {
        T res = sum(last) - sum(first - 1UL);  // cast
        return res;
    }

    std::size_t getSize() { return size; }  // debug用
};

/**
 * T: int, long, long long, ModInt
 * std::string を用いる場合は int 等に変換する
 * 要素数 N と 要素の最大値M に対して 𝑶(N logM)
 * 最大で N^2 / 2 なので，たぶん long long で十分
 */
template <typename T>
long long inversionNumber(const std::vector<T> &v) {
    T v_max = 0;
    for (const T &ve : v) {
        if (v_max < ve) v_max = ve;
    }
    BIT<T> bit(v_max);

    long long res = 0LL;
    for (std::size_t i = 0UL; i < v.size(); ++i) {
        // bit.sum(): これまで出てきたうちで自分より小さい要素の数>=0
        long long sum = i - bit.sum(v.at(i));
        res += sum;
        bit.add(v.at(i));
    }
    return res;
}

int main(void) {
    int n;
    long long k;
    std::cin >> n >> k;

    // aの転倒数
    std::vector<int> a(n);
    for (int &ae : a) std::cin >> ae;
    long long inv_a = inversionNumber(a);

    // aaの転倒数
    std::vector<int> aa(2 * n);
    for (int i = 0; i < 2 * n; ++i) aa.at(i) = (a.at(i % n));
    long long inv_aa = inversionNumber(aa);

    // kf = k * aの転倒数
    long long kf = k * inv_a;
    kf %= MOD;

    // ks = { k(k-1)/2 }( aaの転倒数 - 2 * aの転倒数 )
    long long k_sum = k * (k - 1LL) / 2LL;
    long long sub   = inv_aa - (2LL * inv_a);
    long long ks    = (k_sum % MOD) * sub;
    ks %= MOD;

    long long ans = kf + ks;
    ans %= MOD;

    std::cout << ans << std::endl;

    return 0;
}