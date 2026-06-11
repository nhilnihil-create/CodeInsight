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
    
const int N=505;
const int M=1e9+7;
int a[N];
int n,k,sum=0;
bool chk(int x)
{
	int reqd = 0;
	vector<int> v;
	for(int i = 0; i < n; i++)
	{
		int cur = a[i] % x;
		v.push_back(cur);
	}
	sort(v.begin(), v.end());
	int l = 0, r = v.size() - 1;
	int rem = 0;
	while(l <= r)
	{
		if(rem <= 0)
		{
			rem += v[l];
			reqd += v[l];
			l++;
		}
		else
		{
			rem -= (x - v[r]);
			reqd += (x - v[r]);
			r--;
		}
	}
	if(reqd<=2 * k)
		return 1;
	return 0;
}

void solve()
{
	
	cin>>n>>k;
	f(i,0,n-1) cin>>a[i],sum+=a[i];
	std::vector<int> v;
	for(int i=1;i*i<=sum;i++)
	{
		if(sum%i==0){
		v.pb(i);
		v.pb(sum/i);
		}
	}
	sort(all(v));
	reverse(all(v));
	for(auto X:v)
	{
		if(chk(X))
		{
			cout<<X;
			return;
		}
	}
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

