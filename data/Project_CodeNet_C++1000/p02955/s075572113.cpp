#include <iostream>
#include <algorithm>
#include <complex>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#include <set>
#include <map>
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
const ll INF = 1e18;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
const ll MAX = 100005;
constexpr ll nx[8] = {1,0,-1,0,-1,-1,1,1};
constexpr ll ny[8] = {0,1,0,-1,-1,1,-1,1};
vector<vector<ll>> g(200005);
vector<ll> cnt(200005,0);
vector<bool> done(200005,0);
void dfs(ll v){
    done[v] = 1;
    for (ll u:g[v]){
        if (done[u]) continue;
        cnt[u] += cnt[v];
        dfs(u);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k,c = 0;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        c += a[i];
    }
    vector<ll> use;
    rep(i,1,(ll)sqrt(c)+1){
        if (c%i == 0){
            use.push_back(i);
            use.push_back(c/i);
        }
    }
    RSORT(use);
    rep(i,use.size()){
        ll cnt = 0,p = 0;
        vector<ll> plus,minus;
        rep(j,n){
            ll l = a[j]%use[i];
            if (l <= use[i]-l){
                cnt += l;
                p -= l;
                plus.push_back(use[i]-2*l);
            }
            else{
                cnt += use[i]-l;
                p += use[i]-l;
                minus.push_back(use[i]-2*(use[i]-l));
            }
        }
        if (p > 0){
            p /= use[i];
            SORT(minus);
            rep(j,p){
                cnt += minus[j];
            }
        }
        if (p < 0){
            p = abs(p)/use[i];
            SORT(plus);
            rep(j,p){
                cnt += plus[j];
            }
        }
        if (cnt/2 <= k){
            PRINT(use[i]);
            return 0;
        }
    }
}


