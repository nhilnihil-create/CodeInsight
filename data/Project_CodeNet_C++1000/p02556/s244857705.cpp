#pragma GCC optimize("Ofast")
#pragma GCC optimize("-ffloat-store")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define mod 1000000007
#define inf  1e18
#define ps(x,y)   fixed<<setprecision(y)<<x
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=2e5+10;
const int N = 2e3 + 10;
int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    int n;
	cin>>n;
    int a[maxn],b[maxn];
	for (int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		a[i]=x+y,b[i]=x-y;
	}
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	cout<<max(a[n]-a[1],b[n]-b[1])<<endl;
return 0;   
}