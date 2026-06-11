#include<bits/stdc++.h>
using namespace std;
// 1528
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
    int a,b;cin>>a>>b;
    int ans = INT_MAX;

    for(int i=10*b;i<10*b+10;++i)
    {
    	int x = (int) (i*0.08);
    	if(x==a)
    	{
    		ans = min(ans,i);
    	}
    }
    if(ans==INT_MAX)cout<<"-1";
    else 	cout<<ans<<"\n";
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