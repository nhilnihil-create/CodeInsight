#include<bits/stdc++.h>
using namespace std;
    
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    
#define int long long
#define double long double
    
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (int)x.size()
    
#define ff first
#define ss second
#define mp make_pair
         
#define pb push_back
#define endl "\n" 
         
#define f(i,l,r) for(int i=l;i<=r;i++)
#define rf(i,r,l) for(int i=r;i>=l;i--)    

#define bp __builtin_popcountll
#define inf 1e15
    
const int N=2e5+5;
const int M=1e9+7;
int n,k;
int a[N],f[N];
bool chk(int x)
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int pp=x/f[i];
		ans+=max(0LL,a[i]-pp);
		if(ans>k) return false;
	}
	if(ans<=k) return true;
}
void solve()
{	
	cin>>n>>k;
	f(i,0,n-1) cin>>a[i];
	f(i,0,n-1) cin>>f[i];
	sort(a,a+n);
	sort(f,f+n);
	reverse(a,a+n);
	int low=0,high=1e12;
	int ans=high;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(chk(mid))
		{
			ans=mid;
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	cout<<ans;
}
signed main()  
{
	FAST
    int t=1;
    // cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
    	// cout<<"Case #"<<tc<<": ";
    	solve();
    }
}