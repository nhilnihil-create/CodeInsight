#include<bits/stdc++.h> 
using namespace std; 
#define deb(x) cout <<"\n"<< (#x) << " = " << (x) << "\n"
#define int long long int

void inputoutput()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
}

void dfs(int src , bool *vis , vector<int> v[])
{
	vis[src]=true;
	// cout<<src<<" ";

	for(auto it : v[src])
	{
		if(!vis[it])
			dfs(it,vis,v);
	}
}

int32_t main()
{
    inputoutput();


  int k;
  cin>>k;

  int total=0;

  for(int i=1 ; i<=1e6 ; ++i)
  {
    total=(total*10+7)%k;
    if(total==0)
    {
        cout<<i ;
        return 0;
    }
  }
  cout<<"-1";


    return 0;
}

