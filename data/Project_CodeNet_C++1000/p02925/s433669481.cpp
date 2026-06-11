#include <iostream>
#include <iomanip>
#include <algorithm>
#include <complex>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#include <set>
#include <map>
#include <unordered_map>
#include <numeric>
#include <functional>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline void Yes(bool condition){ if(condition) PRINT("Yes"); else PRINT("No"); }
template<class itr> void cins(itr first,itr last){
    for (auto i = first;i != last;i++){
        cin >> (*i);
    }
}
template<class itr> void array_output(itr start,itr goal){
    string ans = "",k = " ";
    for (auto i = start;i != goal;i++) ans += to_string(*i)+k;
    if (!ans.empty()) ans.pop_back();
    PRINT(ans);
}
ll gcd(ll a, ll b) {
    return a ? gcd(b%a,a) : b;
}
const ll INF = 1e15;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
typedef pair<ll,ll> P;
typedef pair<double,double> point;
const ll MAX = 2010;
constexpr ll nx[8] = {1,0,-1,0,-1,-1,1,1};
constexpr ll ny[8] = {0,1,0,-1,-1,1,-1,1};
ll ans = 0;
vector<int> t_sort(vector<vector<int>> &g){
    vector<int> res,cnt(g.size(),0);
    queue<int> p,q;
    rep(i,g.size()){
        for (int e:g[i]){
            cnt[e]++;
        }
    }
    rep(i,g.size()){
        if (cnt[i] == 0) q.push(i);
    }
    while(!q.empty()){
        ans++;
        while(!q.empty()){
            p.push(q.front());
            q.pop();
        }
        while(!p.empty()){
            int v = p.front();p.pop();
            res.push_back(v);
            for (int u:g[v]){
                cnt[u]--;
                if (cnt[u] == 0){
                    q.push(u);
                }
            }
        }
    }
    return res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> g(n*(n-1)/2),a(n,vector<int>(n-1)),edge(n,vector<int>(n));
    int cnt = 0;
    rep(i,n){
        rep(j,n){
            if (i < j){
                edge[j][i] = edge[i][j] = cnt;
                cnt++;
            }
        }
    }
    rep(i,n){
        rep(j,n-1){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    rep(i,n){
        rep(j,n-2){
            g[edge[i][a[i][j]]].push_back(edge[i][a[i][j+1]]);
        }
    }
    vector<int> t = t_sort(g);
    if (t.size() < n*(n-1)/2){
        PRINT(-1);
    }
    else PRINT(ans);
}
