#include <bits/stdc++.h>
#define M                    1000000007
#define pi                   3.14159265358979323846
#define cel(x,a)             (x+a-1)/a
#define ll                   long long
#define pii                  pair<int, int>
#define pll                  pair<ll, ll>
#define vi                   vector<int>
#define vl                   vector<ll>
#define vpi                  vector<pii>
#define vpl                  vector<pll>
#define pb                   push_back
#define lb                   lower_bound
#define ub                   upper_bound
#define ps(x,y)              fixed<<setprecision(y)<<x
#define pf(x,y)              setfill('x')<<setw(y)
#define mp                   make_pair
#define F                    first
#define S                    second
/*.*Ashish_akj*.*/
#define lcm(m,n)             (m/__gcd(m,n))*n
#define all(v)               v.begin(), v.end()
using namespace std;
const int N = 2e6 + 4;
/*
int ncr(int n, int r) 
{ 
    long long p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 

    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
            long long m = __gcd(p, k); 
            p /= m; 
            k /= m; 

            n--; 
            r--;
        }
    } 

    else
        p = 1; 
    return p;
} */
/*vector<bool>visited;
 vector<vector<int>>adj;
void dfs(int v)
{visited[v]=true;
for(int i:adj[v])
{if(!visited){dfs(i);}
}}
*/
int main()
{ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int n;cin>>n;int ans=0;
for(int i=1; i<n; i++)
{
    int p=(n-1)/i;
    ans+=p;
}
cout<<ans;
    return 0;
}


