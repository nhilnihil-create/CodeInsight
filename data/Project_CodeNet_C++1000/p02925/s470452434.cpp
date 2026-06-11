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


void appendNext(vector<vector<LL>>& match, vector<LL>& cur, LL i, vector<pair<LL,LL>>& q){
    if(cur[i] >= match[i].size()) return;
    LL e = match[i][cur[i]];
    if(cur[e] >= match[e].size()) return;
    LL o = match[e][cur[e]];
    if(o == i){
        q.emplace_back(i, e);
    }
}

int main(){
    LL n;
    cin >> n;
    vector<vector<LL>> match(n, vector<LL>(n-1));
    vector<LL> cnt(n);
    for(LL i = 0; i < n; ++i){
        for(LL j = 0; j < n-1; ++j){
            cin >> match[i][j];
            match[i][j] -= 1;
        }
    }
    vector<LL> cur(n);
    vector<pair<LL,LL>> q;
    for(LL i = 0; i < n; ++i){
        if(match[i][0] < i) continue;
        appendNext(match, cur, i, q);
    }
    LL day = 0;
    while(!q.empty()){
        vector<pair<LL,LL>> q2;
        for(auto p: q){
            cerr << "day=" << day << " " << p << endl;
            cur[p.first] += 1;
            cur[p.second] += 1;
            appendNext(match, cur, p.first, q2);
            appendNext(match, cur, p.second, q2);
        }
        day += 1;
        q2.swap(q);
    }
    for(LL i = 0; i < n; ++i){
        if(cur[i] < n-1){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << day << endl;
    return 0;
}

