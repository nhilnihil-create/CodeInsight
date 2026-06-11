//started 17 minute late
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
#define inf 3e15
    
const int N=2e3+5;
const int M=1e9+7;
void solve()
{
	string s;
	cin>>s;
	int i=0;
	int n=s.size();
	int ans=0;
	int res[n+1]={0};
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='R' && s[i+1]=='L')
		{
			int j=i,r=0,l=0;
			while(j>=0 && s[j]=='R')
			{
				r++;
				j--;
			}
			j=i+1;
			while(j<n && s[j]=='L')
			{
				j++;
				l++;
			}
			res[i]+=r/2;
			res[i+1]+=r/2;
			if(r%2) res[i]++;
			res[i]+=l/2;
			res[i+1]+=l/2;
			if(l%2) res[i+1]++;
			
		}
	}
	f(i,0,n-1)
	cout<<res[i]<<" ";
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

