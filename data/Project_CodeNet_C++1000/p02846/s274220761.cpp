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
	int t1,t2,a1,a2,b1,b2;
	cin>>t1>>t2;
	cin>>a1>>a2;
	cin>>b1>>b2;
	if((a1>b1 && a2>b2) && (a1<b1 && a2<b2))
	{
		cout<<0;
		return;
	}
	if((t1*a1+t2*a2)==(t1*b1+t2*b2))
	{
		cout<<"infinity";
		return;
	}
	
	int dist1=t1*a1+t2*a2;
	int dist2=t1*b1+t2*b2;
	if(dist2>dist1)
    {
    	swap(a1,b1);
    	swap(a2,b2);
    }
    dist1=a1*t1+a2*t2;
    dist2=b1*t1+b2*t2;
 
    if(a1>b1)
    {
    	cout<<0;
    	return;
    }
 
    int diff=dist1-dist2;
    int cnt=(t1*(b1-a1))/diff;
    int ans=2*cnt+1;
    
    if((t1*(b1-a1))%diff==0)
    ans--;
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
