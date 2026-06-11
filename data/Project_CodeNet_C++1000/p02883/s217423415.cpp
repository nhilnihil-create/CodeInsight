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

bool solvable(LL n, LL k, vector<LL>& a, vector<LL>& f, LL m){
    LL needed = 0;
    for(LL i = 0; i < n; ++i){
        needed += max(0LL, a[i] - m / f[i]);
    }
    return needed <= k;
}



int main(){
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n);
    vector<LL> f(n);
    for(LL i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(LL i = 0; i < n; ++i){
        cin >> f[i];
    }
    LL good = 1e+13;
    LL bad = -1;
    sort(a.begin(), a.end(), greater<LL>());
    sort(f.begin(), f.end());
    while(good > bad+1){
        LL middle = (good+bad)/2;
        if(solvable(n, k, a, f, middle)){
            good = middle;
        }else{
            bad = middle;
        }
    }
    cout << good << endl;
    return 0;
}

