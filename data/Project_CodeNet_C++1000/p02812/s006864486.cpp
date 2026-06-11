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
    int n;cin>>n;
    string s;cin>>s;
    int ans =0 ;
    for(int i=0;i<n;++i)
    {
    	if(s[i]!='A')continue;
    	if(i+2>=n)continue;
    	if(s[i+1]=='B' && s[i+2]=='C')
    		ans++;
    }
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