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
typedef pair<double, double> pd;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pld;
 
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pd> vpd;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<vpi> vvpi;

typedef set<pi> spi;

const int INF=INT_MAX;
ll x,y;
ll inv[10000100];
ll FactorialInv[10000100];
ll Factorial[10000100];

ll mymod(ll a,ll b){
    a%=MOD;
    ll result=1;
    while(b>0){
        if(b&1){
            result=(result*a)%MOD;
        }
        a=(a*a)%MOD;
        b>>=1;
    }
    return result;
    
}
ll modInverse(ll n){
    return mymod(n,MOD-2);
}

void init_combination(){
    const int MAX = 10000002;   //1e6+2
    Factorial[0]=1;
    inv[0]=1;
    for(int i=1;i<=MAX;i++){
        Factorial[i]=(Factorial[i-1]*i)%MOD;
    }
    FactorialInv[MAX]=modInverse(Factorial[MAX]);
    for(int i=MAX-1;i>=0;i--){
        FactorialInv[i]=FactorialInv[i+1]*(i+1)%MOD;
    }
    for(int i=1;i<=MAX;i++){
        inv[i]=(FactorialInv[i]*FactorialInv[i-1])%MOD;
    }
}

ll combination(ll n,ll k){
    if(n==k||k==0){
        return 1;
    }
    if(n<k){
        return 0;
    }
    ll ans=(Factorial[n]*FactorialInv[k])%MOD;
    ans=(ans*FactorialInv[n-k])%MOD;
    return ans;
}


int main(){
    int N,K;
    cin>>N>>K;
    N++;
    ll H[N];
    F0R(i,N-1){
        cin>>H[i];
    }
    H[N-1]=0;
    ll dp[N+1][K+1];
    F0R(i, N+1) F0R(j, K+1) {
        dp[i][j] = 1000000000000;
    }
    dp[0][0]=0;
    FOR(i,1,N+1){
        F0R(j,K+1){
            F0R(k,j+1){
                int pos=i-1-k;
                if(pos<0){
                    break;
                }
                int dif=0;
                int lst=0;
                if(pos!=0){
                    lst=H[pos-1];
                }
                dp[i][j]=min(dp[i][j],dp[pos][j-k]+max(0ll,H[i-1]-lst));
            }
        }
    }
    ll ans = 1000000000000;
        F0R(j,K+1){
            ans=min(ans,dp[N][j]);
        }
        out(ans);
}
