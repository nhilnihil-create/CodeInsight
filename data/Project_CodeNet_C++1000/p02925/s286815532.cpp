#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

vector<vector<ll>> id(1005, vector<ll>(1005));
vector<vector<ll>> to(1000010);

ll toId(ll i,ll j){
    if(i>j) swap(i,j);
    return id[i][j];
}
vector<ll> memo(1000010);
vector<ll> caled(1000010);
vector<ll> dp(1000010);
ll dfs(ll v){
    if(memo[v] != 0){
        if(caled[v] == 0){
            return -1;
        }else{
            return dp[v];
        }
    }
    memo[v] = 1;
    ll res = 1;
    for(auto& u:to[v]){
        ll tmp = dfs(u);
        if(tmp == -1){
            return -1;
        }
        cmax(res,tmp+1);
    }
    caled[v] = 1;
    dp[v] = res;
    return res;
}

int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N-1));
    rep(i,N){
        rep(j,N-1){
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    ll V = 0;
    rep(i,N){
        rep(j,N){
            if(i>j)continue;
            id[i][j] = V++;
        }
    }
    rep(i,N){
        rep(j,N-1){
            A[i][j] = toId(i, A[i][j]);
        }
        rep(j,N-2){
            to[A[i][j+1]].push_back(A[i][j]);
        }
    }
    ll ans = 0;
    rep(i,V){
        ll res = dfs(i);
        if(res == -1){
            cout << -1 << endl;
            return 0;
        }
        cmax(ans, res);
    }
    cout << ans << endl;
}