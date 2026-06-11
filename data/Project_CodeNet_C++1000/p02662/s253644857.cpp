#include<bits/stdc++.h>
using namespace std;
 
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
#define ll long long  
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define S second
#define F first
#define die() return 0;
 
 
#define md          998244353
#define fmd         998244353 
#define M           3011
#define N            18
ll exp(ll a,ll b){if(b<0)return 0;ll r=1;while(b){if(b&1)r=r*a%md,r%=md;a=a*a%md;b/=2;}return r;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll F[M],IV[M];

ll dp[M][M];
ll chose(ll n,ll k){
	if(k>n)return 0;
	ll r=F[n];r=r*IV[k];r%=md;r=r*IV[n-k]%md;return r%md;
}
int solve(){
    ll n,i,j,k,m,x,y,z;
    ll s;
    cin>>n>>s;
    vector<ll> v;
    v.pb(0);
    for(i=1;i<=n;++i){
    	cin>>x;v.pb(x);
    }
    ll iv=exp(2,md-2);
    dp[0][0]=1;
    for(i=1;i<=n;++i){
    	for(j=0;j<=s;++j){
    		dp[i][j]+=dp[i-1][j];
    		if(j-v[i]>=0){
    			ll k=dp[i-1][j-v[i]];
    			k=k*iv;k%=md;
    			dp[i][j]+=k;
    		}
    		dp[i][j]%=md;
    	}
    }
    ll p=exp(2,n)*dp[n][s];
    cout<<p%md<<"\n";
 
 
 
 
 
    // trace(f(2,2));
 
 
 
	die();
 
}
void prec(){
	F[0]=IV[0]=1;
	for(int i=1;i<M;++i){
		F[i]=F[i-1]*i%md,F[i]%=md;
		IV[i]=IV[i-1]*exp(i,md-2)%md,IV[i]%=md;
	}
} 
 
int main(){
 
 
#ifndef ONLINE_JUDGE
    double _tBeg=clock();
#endif
 
     
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
    int t;
    t=1;;
    prec();
    // cin>>t;
 
    while(t--){
 
        solve();
    }
 
 
 
 
 
 
#ifndef ONLINE_JUDGE
    double _tEnd=clock();
    // printf("\ntotal time %.6f\n",(_tEnd-_tBeg)/CLOCKS_PER_SEC);
#endif
 
    die();
}