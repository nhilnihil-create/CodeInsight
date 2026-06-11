#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long LL;
template <typename F, typename S> std::ostream& operator<<(ostream& os, const pair<F,S>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; for(const T& a: v){ os << a << ", "; } os << "]"; return os; }
template <typename K, typename V> ostream& operator<<(ostream& os, const map<K,V>& m) {
    os << "{"; for(const auto& p: m){ os << p.first <<":"<< p.second << ", "; } os << "}"; return os; }

vector<LL> prime_list(LL max_val){
    vector<LL> memo(max_val+1);
    vector<LL> res;
    for(LL v = 2; v <= max_val; ++v){
        if(memo[v]) continue;
        res.push_back(v);
        for(LL k = v; k <= max_val; k += v) memo[k] = 1;
    }
    return res;
}

map<LL,LL> factorize(LL val, vector<LL>& primes){
    map<LL,LL> factor;
    for(LL p: primes){
        LL val2 = val;
        while(val % p == 0){
            ++factor[p];
            val /= p;
        }
        if(p*p > val2) break;
    }
    if(val > 1) ++factor[val];
    return factor;
}


int main(){
    LL n, M;
    cin >> n >> M;
    vector<LL> primes = prime_list(1000000);
    map<LL,LL> max_factors;
    bool flag = true;
    LL bin = 0;
    for(LL i = 0; i < n; ++i){
        LL a;
        cin >> a;
        a /= 2;
        for(auto p: factorize(a, primes)){
            if(p.first == 2){
                if(i == 0) bin = p.second;
                else if(bin != p.second) flag = false;
            }
            max_factors[p.first] = max(max_factors[p.first], p.second);
        }
    }
    if(!flag){
        cout << 0 << endl;
        return 0;
    }
    LL base = 1;
    for(auto p: max_factors){
        for(LL i = 0; i < p.second; ++i){
            base *= p.first;
            if(base > M){
                base = 0;
            }
        }
    }
    
    LL ans = 0;
    if(base > 0){
        ans = (M + base) / (base*2);
    }
    cout << ans << endl;
    return 0;
}

