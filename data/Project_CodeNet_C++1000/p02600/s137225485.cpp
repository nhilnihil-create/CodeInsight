#include<bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------------------------
#define FASTIO	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long 
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define frepi(a,b) for(int i=a;i<=b;++i)
// --------------------------------------------------------------------------------

void solve_main()
{
    int x;cin>>x;
    int ans;
    if(x>=1800)ans=1;
    else if(x>=1600)ans=2;
    else if(x>=1400)ans=3;
    else if(x>=1200)ans=4;
    else if(x>=1000)ans=5;
    else if(x>=800)ans=6;
    else if(x>=600)ans=7;
    else if(x>=400)ans=8;
    cout<<ans<<"\n";
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