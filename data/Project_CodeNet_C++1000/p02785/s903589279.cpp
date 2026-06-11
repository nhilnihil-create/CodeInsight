#include<bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------------------------
#define FASTIO	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long 
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define fset(arr,n,val) for(int i=0;i<n;++i) arr[i] = val
#define deb(name,value) cout <<"->>  "<<name<< "= " <<value<<" "
#define frepi(a,b,k) for(int i=a;i<=b;i+=k)
#define frepj(a,b,k) for(int j=a;j<=b;j+=k)
// --------------------------------------------------------------------------------

void solve_main()
{
    int n,k;cin>>n>>k;
    int arr[n];
    frepi(0,n-1,1)cin>>arr[i];
    if(k>=n)
    {
    	cout<<"0\n";
    	return;
    }
    sort(arr,arr+n,greater<int>());
    long long ans = 0;
    for(int i=k;i<n;++i)
    	ans+=arr[i];
    cout<<ans;
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