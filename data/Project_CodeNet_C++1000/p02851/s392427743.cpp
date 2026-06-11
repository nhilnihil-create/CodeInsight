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


int main(){
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n);
    for(LL i = 0; i < n; ++i){
        cin >> a[i];
    }
    map<LL,LL> cnt;
    LL ans = 0;
    LL total = 0, total2 = 0;
    for(LL i = 0; i < n; ++i){
        ++cnt[total];
        total = (total + a[i] + k-1) % k;
        if(i >= k-1){
            --cnt[total2];
            total2 = (total2 + a[i-k+1] +k-1) % k;
        }
        ans += cnt[total];
        //cerr << ans << ", " << cnt << ", total=" << total  << endl;
    }
    cout << ans << endl;
    return 0;
}

