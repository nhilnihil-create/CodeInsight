#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <random>

// @ ローリングハッシュ構造
class RollingHash {
private:
    // 範囲チェックを行うかのマクロ
    #define RANGE_CHECK_ROLLING_HASH false

    unsigned long long int base;
    std::vector<unsigned long long int> hash;
    std::vector<unsigned long long int> base_power;

    static constexpr unsigned long long int mask30 = (1ULL << 30) - 1;
    static constexpr unsigned long long int mask31 = (1ULL << 31) - 1;
    static constexpr unsigned long long int mask61 = (1ULL << 61) - 1;
    static constexpr unsigned long long int mod_pr = (1ULL << 61) - 1;

public:
    // x * y mod (2^61 - 1) を計算する関数 : ただし, 0 ≤ x, y < 2^61 とする
    static unsigned long long int mult(const unsigned long long int x, const unsigned long long int y){
        const unsigned long long int xh = x >> 31, xl = x & mask31;
        const unsigned long long int yh = y >> 31, yl = y & mask31;
        const unsigned long long int z  = xh * yl + xl * yh;
        const unsigned long long int zh = z >> 30, zl = z & mask30;
        return evalMod(2 * xh * yh + zh + (zl << 31) + xl * yl);
    }
    // 与えられた数 x の mod (2^61 - 1) を計算する関数
    static unsigned long long int evalMod(unsigned long long int x){
        const unsigned long long int res = (x >> 61) + (x & mask61);
        return (res >= mod_pr) ? res - mod_pr : res;
    }
private:
    
    template <class InputIterator>
    void initialize(InputIterator first, InputIterator last){
        const int len = last - first;
        hash.resize(len + 1); hash[0] = 0;
        for(int idx = 0; idx < len; ++idx){ 
            hash[idx + 1] = evalMod(mult(hash[idx], base) + static_cast<unsigned long long int>(*first++));
        }
        base_power.resize(len + 1); base_power[0] = 1;
        for(int idx = 0; idx < len; ++idx){
            base_power[idx + 1] = mult(base_power[idx], base);
        }
    }
public:
    // コンストラクター
    template <class InputIterator>
    RollingHash(InputIterator first, InputIterator last){
        std::random_device seed;
        std::default_random_engine engine(seed());
        std::uniform_int_distribution<unsigned long long int> dist(2, mod_pr - 1);
        base = dist(engine);
        initialize(first, last);
    }
    // コンストラクタ (baseに対する引数有り)
    template <class InputIterator> 
    RollingHash(InputIterator first, InputIterator last, unsigned long long int base_arg):base(base_arg){ initialize(first, last); }
    // コンストラクタ (文字列)
    RollingHash(const std::string& str_arg){
        std::random_device seed;
        std::default_random_engine engine(seed());
        std::uniform_int_distribution<unsigned long long int> dist(2, mod_pr - 1);
        base = dist(engine);
        initialize(str_arg.cbegin(), str_arg.cend());
    }
    RollingHash(const std::string& str_arg, unsigned long long int base_arg):base(base_arg){ initialize(str_arg.cbegin(), str_arg.cend());}
    
    // 区間 [l, r) (0-indexed) の ハッシュ値を得る関数 : O(1)
    unsigned long long int getHash(int l, int r) const {
        #if RANGE_CHECK_ROLLING_HASH
            assert(0 <= and l <= r and r < static_cast<int>(hash.size()));
        #endif
        const unsigned long long int val_tmp = mult(hash[l], base_power[r - l]);
        return (hash[r] >= val_tmp) ? hash[r] - val_tmp : hash[r] + mod_pr - val_tmp;
    }
    // 基底を返す関数 : O(1)
    unsigned long long int getBase(void) const { return base; }
};

int main(void){
    //std::cin.tie(nullptr); std::cin.sync_with_stdio(false);

    int n; std::string S; std::cin >> n >> S;
    RollingHash RH(S);
    int ok = 0, ng = n;
    while(ng - ok > 1){
        const int l = (ok + ng) >> 1;
        bool exist = false;
        for(int i = 0; i + l + l <= n; ++i){
            const unsigned long long int hash1 = RH.getHash(i, i + l);
            for(int j = i + l; j + l <= n; ++j) if(hash1 == RH.getHash(j, j + l)){ exist = true; break; }
            if(exist) break;
        }
        if(exist) ok = l; else ng = l;
    }
    std::cout << ok << '\n';

    return 0;
}