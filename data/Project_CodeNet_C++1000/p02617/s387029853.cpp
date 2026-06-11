#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test int t;cin>>t;while(t--)
#define REP(i,n) for (int i = 1; i <= n; i++)
#define MOD 1000000007
#define ll long long
#define int ll
#define pb push_back
#define ii pair<int,int>
#define llll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<ii>
#define vllll vector<llll>
#define ff first
#define ss second
#define INF 1000000000
#define HINF 1000000000000000
#define mem(a,b) memset(a,b,sizeof(a))
#define deb(x) cout<<#x<<'='<<x<<endl
const double pi = 3.14159265358979323846;

ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
int C(int n,int k)
{
	int ans=1;
	if(k>n-k)
	k=n-k;
	for(int i=1;i<=k;i++)
	ans*=(n-i+1),ans/=i;
	return ans;
}

void solve()
{

	int h,w,i=0,j=0,k=0,m,n,p,e,f=0,sum=0,cnt=0;
	cin>>n;
	for(i=1;i<=n;i++)
	sum+=i*(n-i+1);
	for(i=0;i<n-1;i++)
	{
	    cin>>j>>k;
      if(k<j)swap(j,k);
	    sum-=j*(n-k+1);
	}
	cout<<sum;
}
int32_t main() {
    fast
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w+", stdout);
    //test
    {
        
        solve();
		
		      
    }
    return 0;
}
  
