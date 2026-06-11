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
    int n,k;cin>>n>>k;
    bool hash[n+1];
    mset(hash,0);
    while(k--)
    {
    	int d;cin>>d;
    	frepi(1,d,1)
    	{
    		int x;cin>>x;
    		hash[x]=true;
    	}
    }
    int ans = 0;
    frepi(1,n,1)
    {
    	if(hash[i]==false)ans++;
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