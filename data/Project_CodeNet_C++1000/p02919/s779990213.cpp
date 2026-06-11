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


// import here

int main(){
    LL n;
    cin >> n;
    vector<LL> p(n);
    vector<LL> idx(n);
    for(LL i = 0; i < n; ++i){
        cin >> p[i];
        idx[p[i]-1] = i;
    }
    LL ans = 0;
    set<LL> used;
    used.insert(idx[n-1]);
    used.insert(-2);
    used.insert(-1);
    used.insert(n);
    used.insert(n+1);
    for(LL i = n-2; i >= 0; --i){
        auto it = used.lower_bound(idx[i]);
        LL r1 = min(n, *it);
        LL r2 = min(n, *used.lower_bound(r1+1));
        LL l1 = max<LL>(-1, *(--it));
        LL l2 = max<LL>(-1, *(--it));
        LL cnt = (r2-r1)*(idx[i]-l1) + (l2-l1)*(idx[i]-r1);
        ans += cnt * (i+1);
        //cerr << (i+1) << ", " << cnt << endl;
        used.insert(idx[i]);
    }
    cout << ans << endl;
    return 0;
}

