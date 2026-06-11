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
    int a,b,c;cin>>a>>b>>c;
    int k;cin>>k;
    int count = 0;
    while(b<=a)b = b*2,count++;
    while(c<=b)c = c*2,count++;
    cout<<((count<=k)?"Yes\n":"No");
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