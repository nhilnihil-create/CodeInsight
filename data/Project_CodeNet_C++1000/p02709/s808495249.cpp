#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

ll n;
vector<ll>a;

ll dp[2020][2020];

vector<ll>id;

ll rec(ll i,ll j){
    if(dp[i][j]>=0)return dp[i][j];
    ll res = 0;
    ll move = n+i-j;
    if(i>0){
        ll l = rec(i-1,j);
        l += a[id[move-1]]*abs(id[move-1]-(i-1));
        chmax(res,l);
    }
    if(j<n){
        ll r = rec(i,j+1);
        r += a[id[move-1]]*abs(id[move-1]-j);
        chmax(res,r);
    }
    return dp[i][j]=res;
}

int main(){
    cin >> n;
    a.resize(n);
    vector<P>vec(n);
    rep(i,n){
        cin>>a[i];
        vec[i]={a[i],i};
    }
    sort(vec.rbegin(),vec.rend());
    id.resize(n);
    rep(i,n){
        id[i]=vec[i].second;//i番目に大きい要素が左から何番目か
    }
    ll ans = 0;
    rep(i,2020)rep(j,2020)dp[i][j]=-1;


    rep(i,n+1){
        chmax(ans,rec(i,i));
    }

    cout << ans << endl;



    return 0;
}