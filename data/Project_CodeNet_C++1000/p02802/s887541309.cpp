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
    int n,m;cin>>n>>m;
    bool done[n+1];
    int wa[n+1];
    mset(wa,0);
    mset(done,0);
    int ac = 0;
    int penalty = 0;
    while(m--)
    {
    	int u;cin>>u;
    	string s;cin>>s;
    	if(done[u])
    		continue;
    	if(s=="AC")
    	{
    		ac++;
    		done[u] = true;
    		continue;
    	}
    	if(s=="WA")
    	{
    		wa[u]++;
    	}
    }
    for(int i=1;i<=n;++i)
    {
    	if(done[i])
    		penalty+=wa[i];
    }
    cout<<ac<<" "<<penalty;
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