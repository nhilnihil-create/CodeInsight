#include<bits/stdc++.h>
using namespace std;
#define very_slow       ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int             long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vec             vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define inf             1e18
#define MAX             1e9
#define MIN            -1e9
#define no_of_test(x)   int x; cin>>x; while(x--)
const double pi=3.14159265359;
const int mod = 1e9 + 6;
//Actual Code Is At The Top
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
int binary_exponentation(int a, int b)
{
	int ret = 1;
	while (b)
	{
		if (b & 1) ret = (ret * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ret;
}
int nodes,edges;
vector<int>adj[100001];
int vis[100001];
void dfs(int node)
{
    if(vis[node]) return;
    vis[node]=1;
    for(auto child:adj[node])
    {
        dfs(child);
    }
}
int32_t main()
{   
	very_slow
//	no_of_test(x)
	{  
	   int n;
       cin>>n;
       while(n--)
       {
           cout<<"ACL";
       }
       cout<<'\n';
	}
	return 0;
}