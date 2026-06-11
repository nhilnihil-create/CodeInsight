#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> G(N*3+10);
    ll u,v;
    rep(i,M){
        cin >> u >> v;
        u--;v--;
        G[u].push_back(v+N);
        G[u+N].push_back(v+N+N);
        G[u+N+N].push_back(v);
    }
    ll S,T;
    cin >> S >> T;
    S--;T--;
    queue<ll> que;
    que.push(S);
    vector<ll> memo(N*3+10, 1e18);
    memo[S] = 0;
    while(!que.empty()){
        ll a =  que.front();
        que.pop();
        for(auto& b:G[a]){
            if(memo[b] != 1e18) continue;
            memo[b] = memo[a] + 1;
            que.push(b);
        }
    }
    if(memo[T] == 1e18){
        cout << -1 << endl;
    }else{
        cout << memo[T]/3 << endl;
    }
}