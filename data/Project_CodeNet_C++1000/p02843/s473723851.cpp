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
    
const int N=1e5+5;
const int M=1e9+7;
void solve()
{
	int x[N]={0};
	x[0]=1;
	int n;
	cin>>n;
	f(i,100,105)
	{
		f(j,0,N-1)
		{
			if(j-i>=0 && x[j-i]>=1)
			x[j]=1;
		}
	}
	if(x[n]==1) cout<<1;
	else cout<<0;
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
