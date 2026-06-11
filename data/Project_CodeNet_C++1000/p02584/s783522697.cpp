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


   int x,k,d;
   cin>>x>>k>>d ; 
   x=abs(x);

   int hopes=min(k,x/d);
   k=k-hopes;
   x=x-hopes*d;

   if(k%2)
        cout<<d-x;
    else
        cout<<x;
    



    return 0;
}

