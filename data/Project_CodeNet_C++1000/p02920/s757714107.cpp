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


bool solve(LL n, vector<LL>& s){
    multiset<LL> cand(s.begin(), s.end());
    multiset<LL> used;
    LL v = *cand.begin();
    used.insert(v);
    cand.erase(v);
    for(LL i = 0; i < n; ++i){
        //cerr << "i=" << i << endl;
        vector<LL> tmp(used.begin(), used.end());
        for(LL v: tmp){
            auto it = cand.lower_bound(v+1);
            if(it == cand.end()) return false;
            //cerr << v << ", " << *it << endl;
            used.insert(*it);
            cand.erase(it);
        }
    }
    return true;
}

int main(){
    LL n;
    cin >> n;
    vector<LL> s(1LL<<n);
    for(LL i = 0; i < (1LL<<n); ++i){
        cin >> s[i];
        s[i] *= -1;
    }
    if(solve(n, s)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}

