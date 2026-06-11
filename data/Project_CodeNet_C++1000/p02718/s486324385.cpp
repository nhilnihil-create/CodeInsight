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
    int n,m;cin>>n>>m;
    int arr[n];
    ll total_votes = 0;
    frepi(0,n-1,1)
    {
    	cin>>arr[i];
    	total_votes+=arr[i];
    }
    double req = ((double)total_votes/((double)m*(4.0)));
    sort(arr,arr+n,greater<int>());
    int count = 0;
    for(int i=0;i<n;++i)
    {
    	if(arr[i]>=req)
    	{
    		count++;
    	}
    }
    if(count>=m)
    	cout<<"Yes\n";
    else
    	cout<<"No\n";
    
}

int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("/home/suryakant/input.txt","r",stdin);
        freopen("/home/suryakant/output.txt","w",stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve_main();
    }
    
}