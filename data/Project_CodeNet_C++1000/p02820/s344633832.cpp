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

LL getGain(LL r, LL s, LL p, char c){
    if(c == 's') return r;
    if(c == 'p') return s;
    if(c == 'r') return p;
    return 0;
}

LL solve(LL r, LL s, LL p, string str){
    LL n = str.size();
    vector<LL> win(n+1);
    vector<LL> lose(n+1);
    for(LL i = 0; i < n; ++i){
        if(i == 0 || str[i-1] != str[i]){
            win[i+1] = max(win[i+1], win[i] + getGain(r,s,p,str[i]));
            lose[i+1] = max(lose[i+1], win[i]);
        }else{
            win[i+1] = max(win[i+1], lose[i] + getGain(r,s,p,str[i]));
            lose[i+1] = max(lose[i+1], win[i]);
        }
    }
    return max(win[n], lose[n]);
}

int main(){
    LL n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;
    LL ans = 0;
    for(LL i = 0; i < k; ++i){
        string str;
        for(LL j = i; j < t.size(); j += k){
            str += t[j];
        }
        ans += solve(r, s, p, str);
    }
    cout << ans << endl;
    return 0;
}

