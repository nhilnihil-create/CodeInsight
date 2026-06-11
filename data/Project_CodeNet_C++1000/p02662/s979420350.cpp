#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const LL mod=998244353;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={1,0,-1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,-1,-1,1,1};


int M_N = 199999;

vector<LL> fact;
vector<LL> inver(M_N+1);
 
LL combi(int n,int r){
    if(n<r||n<0||r<0) return 0;
    return fact[n]%mod*inver[n-r]%mod*inver[r]%mod;
}
 
 
LL fpow(LL a, LL n){
    LL x = 1;
    while(n > 0){
        if(n&1){
            x=x*a%mod;
        }
        a=a*a%mod;
        n >>= 1;
    }
    return x;
}
 
void set_combi(){
    LL s=1;
    fact.push_back(1);
    for(int i=1;i<=M_N;i++){
        s*=i;
        s%=mod;
        fact.push_back(s);
    }
    inver[M_N]=fpow(fact[M_N],mod-2);
    for(int i=M_N-1;i>=0;i--){
        inver[i]=inver[i+1]*(i+1)%mod;
    }
}
 

int main(){
    int n,s;cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<LL>> dp(n+1,vector<LL> (7000,0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i+1][j+a[i]] = (dp[i+1][j+a[i]] + dp[i][j])%mod;
            dp[i+1][j] = (dp[i+1][j] + 2 * dp[i][j])%mod;
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}
