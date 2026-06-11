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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int win = -1;
    bool ok = true;
    while(1)
    {
    	if(!ok)
    	{
    		a-=d;
    		if(a<1)
    		{
    			win = 2;
    			break;
    		}
    	}
    	else
    	{
    		c-=b;
    		if(c<1)
    		{
    			win=1;
    			break;
    		}
    	}
    	ok = !ok;
    }
    if(win==1)
    	cout<<"Yes";
    else cout<<"No";
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