#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define all(ppp) ppp.begin(),ppp.end()
#define out(ppp) cout<<(ppp)<<endl
#define out1(ppp) cout<<(ppp) 
#define MAX_CHAR 256

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define pb push_back

typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<vpi> vvpi;

typedef set<pi> spi;

const int INF=INT_MAX;

ll dp[2010][2010]={0};
void solve(){
    ll N,M;
    cin>>N>>M;
    vl S(N);
    vl T(M);
    F0R(i,N){
        cin>>S[i];
    }
    F0R(i,M){
        cin>>T[i];
    }
    dp[0][0]=1;
    for(ll i=0;i<=N;i++){
        for(ll j=0;j<=M;j++){
            if(i>0) dp[i][j]+=dp[i-1][j];
            if(j>0) dp[i][j]+=dp[i][j-1];
            if(i>0&&j>0&&S[i-1]!=T[j-1])dp[i][j]+=MOD-dp[i-1][j-1];
            dp[i][j]%=MOD;
        }
    }
    dp[N][M]=(MOD+dp[N][M])%MOD;
    out(dp[N][M]);
}

int main(){
    solve();
    return 0;
}