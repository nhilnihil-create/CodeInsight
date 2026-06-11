#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define float long double
#define pb push_back
#define fi first
#define se second
#define vii vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define pq priority_queue<int>
#define test int tcase; cin>>tcase; for(int tc = 1; tc <= tcase; tc++)
#define inp(a,n,f) int a[n+f];for(int hh=f;hh<n+f;hh++)cin>>a[hh];
#define prdec(k) cout<<fixed<<setprecision(k);
#define mem(a,k) memset(a,k,sizeof(a))
#define ub upper_bound
#define lb lower_bound
#define mii map<int,int>
#define all(v) v.begin(),v.end()
#define inf LLONG_MAX
int exp(int x,int y,int mod){int res=1;x=x%mod;while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
int modinv(int x,int mod){return exp(x,mod-2,mod);}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k,a,b;
    cin>>k>>a>>b;
    bool ok=0;
    for(int i=a;i<=b;i++)
    	if(i%k==0)
    		ok=1;
    cout<<(ok?"OK":"NG");
    return 0;
}