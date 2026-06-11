#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <functional>
 
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
ll dy[8] = {1,0,-1,0,1,-1,1,-1};
ll dx[8] = {0,1,0,-1,1,-1,-1,1};
const double pi = acos(-1);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){cout << a << " " << b << " " << c << endl;}
#define INT_MAX 1<<30;
const int MAX = 1020000;
const double EPS = 1e-6;
const int mod = 1e9+7;
 
int main(){
    ll n; cin >> n;
    vl a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    priority_queue<P> pq;
    rep(i,n){
        if(a[i]>b[i]){
            puts("-1");
            return 0;
        }else if(a[i]<b[i]){
            pq.emplace(b[i],i);
        }
    }
    ll ans = 0;
    while(!pq.empty()){
        P p = pq.top(); pq.pop();
        ll u = p.second;
        ll t = 0;
        if(u==0) t = b[n-1] + b[1];
        else t = b[u-1] + b[(u+1)%n];
        if(p.first-a[u] < t){
            puts("-1");
            return 0;
        }else{
            ans += (p.first-a[u])/t;
            b[u] -= (p.first-a[u])/t * t;
            if(b[u] != a[u]) pq.emplace(b[u],u);
        }
    }
    cout << ans << endl;
}