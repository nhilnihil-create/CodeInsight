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

bool palind(string s)
{
	int n=s.size();
	for(int i=0;i<=n/2;++i)
	{
		if(s[i]!=s[n-i-1])
			return false;
	}
	return true;
}

void solve_main()
{
    string s;cin>>s;
    int n = s.size();
    string s1 = s.substr(0,(n-1)/2);
    string s2 = s.substr((n+3)/2-1,(n-3)/2+1);
    if(palind(s1) && palind(s2) && palind(s))
    	cout<<"Yes";
    else
    	cout<<"No";
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