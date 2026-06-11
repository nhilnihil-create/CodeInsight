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
    LL n;
    cin >> n;
    vector<pair<LL,LL>> p(n);
    for(LL i = 0; i < n; ++i){
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end(), [](pair<LL,LL>& op1, pair<LL,LL>& op2){
        return atan2(op1.first, op1.second) < atan2(op2.first, op2.second);
    });
    double ans = 0;
    for(LL i = 0; i < n; ++i){
        double dx = 0, dy = 0;
        for(LL j = 0; j < n; ++j){
            dx += p[(i+j)%n].first;
            dy += p[(i+j)%n].second;
            ans = max(ans, sqrt(dx*dx + dy*dy));
        }
    }

    cout << setprecision(13) << ans << endl;
    return 0;
}

