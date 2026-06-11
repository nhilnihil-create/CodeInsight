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


bool check(vector<LL>& a, vector<LL>& rest, LL d, LL k){
    LL n = a.size();
    for(LL i = 0; i < n; ++i){
        rest[i] = a[i] % d;
    }
    sort(rest.begin(), rest.end());
    LL cur = 0;
    LL sub_total1 = 0;
    while(cur < n){
        if(sub_total1 + rest[cur] > k) break;
        sub_total1 += rest[cur];
        ++cur;
    }
    LL sub_total2 = (n-cur) * d - accumulate(rest.begin() + cur, rest.end(), 0);
    return sub_total2 <= k;
}

int main(){
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n);
    for(LL i = 0; i < n; ++i){
        cin >> a[i];
    }
    LL total = accumulate(a.begin(), a.end(), 0);
    cerr << "total=" << total << endl;
    LL ans = 1;
    vector<LL> rest(n);
    for(LL d = 1; d <= 1000000; ++d){
        if(total % d != 0) continue;
        if(check(a, rest, d, k)) ans = max(ans, d);
        if(check(a, rest, total / d, k)) ans = max(ans, total / d);
    }

    cout << ans << endl;
    return 0;
}

