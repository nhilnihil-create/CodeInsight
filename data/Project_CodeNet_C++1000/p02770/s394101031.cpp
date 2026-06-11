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
    LL k, q;
    cin >> k >> q;
    vector<LL> d(k);
    for(LL i = 0; i < k; ++i){
        cin >> d[i];
    }
    for(LL i = 0; i < q; ++i){
        LL n, x, m;
        cin >> n >> x >> m;
        vector<LL> a(k+2);
        a[0] = x % m;
        for(LL j = 1; j-1 <= k; ++j){
            a[j] = a[j-1] + d[(j-1)%k] % m;
        }
        LL n2 = (n-1) / k;
        LL r = (n-1) % k;

        LL last_val = a[0] + (a[k] - a[0]) * n2 + (a[r] - a[0]);
        LL cnt = 0;
        for(LL j = 0; j < k; ++j){
            if(a[j+1] == a[j]) cnt++;
        }
        cnt *= n2;
        for(LL j = 0; j+1 <= r; ++j){
            if(a[j+1] == a[j]) cnt++;
        }
        //cerr << a << endl;
        //cerr << "last_val=" << last_val << " " << last_val / m << " " << last_val % m << endl;
        cout << (n-1) - last_val / m - cnt  << endl;
    }
    return 0;
}

