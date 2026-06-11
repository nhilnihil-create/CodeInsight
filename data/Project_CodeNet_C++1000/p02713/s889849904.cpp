#include<bits/stdc++.h>
using namespace std;
// 1202
// --------------------------------------------------------------------------------
#define fastio	ios_base::sync_with_stio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long 
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define deb(name,value) cout <<"->>  "<<name<< "= " <<value<<" "
#define frepi(a,b,k) for(int i=a;i<=b;i+=k)
#define frepj(a,b,k) for(int j=a;j<=b;j+=k)
// --------------------------------------------------------------------------------
 
int gcd(int a,int b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}
 
void solve_main()
{
    int k;cin>>k;
    ll ans = 0;
    for(int i=1;i<=k;++i)
    {
    	for(int j=1;j<=k;++j)
    	{
    		int x = gcd(i,j);
    		for(int z=1;z<=k;++z)
    		{
    			ans+=(gcd(x,z));
    		}
    	}
    }
    cout<<ans;
 
}
 
int main()
{
	// #ifndef ONLINE_JUDGE
 //    	freopen("/home/suryakant/input.txt","r",stdin);
 //        freopen("/home/suryakant/output.txt","w",stdout);
 //    #endif
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve_main();
    }
    
}