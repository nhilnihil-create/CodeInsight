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
    int n;cin>>n;
    unordered_set<int>st;
    frepi(1,n,1)
    {
    	int x;cin>>x;
    	st.insert(x);
    }
    if(st.size()==n)
    	cout<<"YES\n";
    else
    	cout<<"NO\n";
}

int main()
{

	// #ifndef ONLINE_JUDGE
	//	freopen("/home/suryakant/input.txt","r",stdin);
	//	freopen("/home/suryakant/output.txt","w",stdout);
	// #endif

    int t=1;
    // cin>>t;
    while(t--)
    {
        solve_main();
    }
    
}