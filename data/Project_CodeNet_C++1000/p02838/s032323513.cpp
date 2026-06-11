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

LL MOD = 1000000007;

int main(){
    LL n;
    cin >> n;
    vector<LL> a(n);
    for(LL i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<LL> bit_cnt(61);
    for(LL i = 0; i < n; ++i){
        for(LL j = 0; j < 61; ++j){
            if(a[i] & (1LL<<j)) bit_cnt[j]++;
        }
    }
    LL ans = 0;
    for(LL j = 0; j < 61; ++j){
        ans = (ans + (1LL<<j) % MOD * bit_cnt[j] % MOD * (n - bit_cnt[j]) % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}

