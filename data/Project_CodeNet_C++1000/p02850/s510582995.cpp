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

void color(LL cur, LL parent, map<pair<LL,LL>, LL>& col, vector<vector<LL>>& edge){
    LL c = 0;
    for(LL next: edge[cur]){
        if(next == parent) continue;
        ++c;
        if(c == col[pair<LL,LL>(parent,cur)]) ++c;
        col[pair<LL,LL>(cur, next)] = c;
        col[pair<LL,LL>(next, cur)] = c;
        color(next, cur, col, edge);
    }
}

int main(){
    LL n;
    cin >> n;
    vector<vector<LL>> edge(n);
    vector<pair<LL,LL>> data;
    for(LL i = 0; i < n-1; ++i){
        LL a, b;
        cin >> a >> b;
        --a; --b;
        data.emplace_back(a, b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    map<pair<LL,LL>, LL> col;
    color(0, -1, col, edge);
    vector<LL> ans(n-1);
    for(LL i = 0; i < n-1; ++i){
        ans[i] = col[data[i]];
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
    for(LL i = 0; i < ans.size(); ++i){
        cout << ans[i] << endl;
    }
    return 0;
}

