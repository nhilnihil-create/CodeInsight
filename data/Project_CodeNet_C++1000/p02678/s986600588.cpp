#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    ll a, b;
    rep(i,M){
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<ll> que;
    que.push(0);
    vector<ll> memo(N,-1);
    memo[0] = -2;
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(auto& u:G[v]){
            if(memo[u] != -1) continue;
            memo[u] = v;
            que.push(u);
        }
    }
    cout << "Yes" << endl;
    REP(i,1,N){
        cout << memo[i] + 1 << endl;
    }
}