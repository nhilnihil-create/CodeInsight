#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll N;
    string S;
    cin >> N >> S;
    if (S[0]=='W'||S[2*N-1]=='W'){
        cout << 0 << endl;
        return 0;
    }
    vector<ll> dp(2*N);
    dp[0]=1;
    ll now=1;
    rep2(i,1,2*N){
        dp[i]=dp[i-1];
        if (S[i]=='B'&&now%2==0) ++now;
        else if (S[i]=='W'&&now%2==1) ++now;
        else{
            dp[i]=dp[i]*now%MOD;
            --now;
            if (now<0){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if (now!=0){
        cout << 0 << endl;
        return 0;
    }
    ll ans=dp[2*N-1];
    rep(i,N) ans=ans*(i+1)%MOD;
    cout << ans << endl;
}