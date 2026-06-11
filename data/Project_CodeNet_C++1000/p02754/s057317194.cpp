#include<bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------------------------
#define fastio	ios_base::sync_with_stio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long 
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define deb(name,value) cout <<"->>  "<<name<< "= " <<value<<" "
#define frepi(a,b,k) for(int i=a;i<=b;i+=k)
#define frepj(a,b,k) for(int j=a;j<=b;j+=k)
// --------------------------------------------------------------------------------


void solve_main()
{
    ll n,a,b;cin>>n>>a>>b;
    ll ans = 0;
    if(n%(a+b)==0)
    {
    	cout<<a*(n/(a+b));
    }
    else
    {
    	ans+=(n/(a+b))*(a);
    	if(n%(a+b)>=a)
    	{
    		ans+=a;
    	}
    	else
    		ans+=(n%(a+b));
    	cout<<ans;
    }
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