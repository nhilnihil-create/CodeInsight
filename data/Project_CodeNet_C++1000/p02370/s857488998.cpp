#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline bool Yes(bool condition){ if(condition) PRINT("Yes"); else PRINT("No"); }
template<class itr> void cins(itr first,itr last){
    for (auto i = first;i != last;i++){
        cin >> (*i);
    }
}
template<class itr> void array_output(itr start,itr goal){
    string ans = "";
    for (auto i = start;i != goal;i++) ans += to_string(*i)+" ";
    if (!ans.empty()) ans.pop_back();
    PRINT(ans);
}
constexpr const ll INF = 1e15;
constexpr const ll MOD = 1000000007;
constexpr const ll MAX = 1e9;
constexpr ll nx[4] = {1,0,-1,0};
constexpr ll ny[4] = {0,1,0,-1};
typedef pair<ll,ll> P;
vector<int> t_sort(vector<vector<int>> &g){
    vector<int> res,cnt(g.size(),0);
    queue<int> q;
    rep(i,g.size()){
        for (int e:g[i]){
            cnt[e]++;
        }
    }
    rep(i,g.size()){
        if (cnt[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int v = q.front();q.pop();
        res.push_back(v);
        for (int u:g[v]){
            cnt[u]--;
            if (cnt[u] == 0){
                q.push(u);
            }
        }
    }
    return res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v,e,s,t;
    cin >> v >> e;
    vector<vector<int>> g(v);
    rep(i,e){
        cin >> s >> t;
        g[s].push_back(t);
    }
    vector<int> k = t_sort(g);
    rep(i,v){
        PRINT(k[i]);
    }
}

