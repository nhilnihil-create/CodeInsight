#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define mod 998244353
#define floop(i,a,b) for (int i=(a);i<(b);i++)
#define rloop(i,a,b) for (int i=(a);i>=(b);i--)
#define floopeq(i,a,b) for (int i=(a);i<(b);i++)
#define pa pair<int,int>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll power(ll x, ll y, ll p)  
{  
    ll res = 1;x = x % p;if (x == 0)return 0;while (y > 0)  
    {if (y & 1) res = (res*x) % p;  y = y>>1; x = (x*x) % p;  }  return res;  
}
void dfs(int i,int j,int n,int m,vector<vector<char>>a,vector<vector<bool>>&vis)
{
    vis[i][j]=1;
    if(i<(n-1) && vis[i+1][j]==0 && (a[i+1][j]!='#'))
    {
        dfs(i+1,j,n,m,a,vis);
    }
    if(i>0 && vis[i-1][j]==0 &&(a[i-1][j]!='#'))
    {
        dfs(i-1,j,n,m,a,vis);
    }
    if(j<(m-1) && vis[i][j+1]==0 && (a[i][j+1]!='#'))
    {
        dfs(i,j+1,n,m,a,vis);
    }
    if(j>0 && vis[i][j-1]==0 && ((a[i][j-1]!='#')))
    {
        dfs(i,j-1,n,m,a,vis);
    }
}
void solve()
{
	string s;
	cin>>s;
	vector<char>p;
	for(auto x:s){
		if(x=='?')
		{
			p.pb('D');
		}
		else
			p.pb(x);
	}
	for(auto x:p){
		cout<<x;
	}
}
int main() 
{ 
    
    int t;
    t=1;
    while(t--){
    	solve();
    }
    return 0; 

} 
