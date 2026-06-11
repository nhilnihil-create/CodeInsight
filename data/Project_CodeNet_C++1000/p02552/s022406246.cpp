// NEVER GIVE UP //

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<bitset>
#include<iterator>


#define int long long int
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define r0 return 0;
#define tc int t;cin>>t;while(t--)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define vi vector<int>
#define vii vector<long long int>
#define SORT(v) sort(v.begin(),v.end());
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define md 998244353
#define inf 1000000000000000 //1e15
#define gcd __gcd
#define lcm(a,b) ((a)*(b))/gcd(a,b)
#define all(a) (a).begin(),(a).end()

int min(int a,int b){
    return (a<b)?a:b;
}
int max(int a,int b){
    return (a>b)?a:b;
}
int fp(int a,int b){
    if(b==0) return 1;
    int x=fp(a,b/2);
    x=(x*x)%mod;
    if(b&1) x=(x*a)%mod;
    return x;
}
int factorial(int n)
{
    int fact=1;
    for(int i=2;i<=n;i++)
    fact=fact*i;

    return fact;
}
int ncr(int n,int r)
{
    return factorial(n)/(factorial(r)*factorial(n-r));
}
int binomialCoeff(int n,int k)
{
    int dp[k+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=min(i,k);j>0;j--)
        dp[j]=(dp[j]+dp[j-1])%mod;
    }
    return dp[k]%mod;

}
/*

void input()
{
    int n;
    for0(i,n)
        for0(j,n)
            cin>>adj[i][j];

}


void dfs(int s){
    visited[s]=true;
    for(auto u:adj[s]){
        if(!visited[u]){
            //parent[u]=s;
            dis[u]=dis[s]+1;
            dfs(u);
        }
    }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s]=true;
    dis[s]=0;
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(auto x:adj[u]){
            if(!visited[x]){
                //parent[x]=u;
                visited[x]=true;
                dis[x]=dis[u]+1;
                q.push(x);
            }
        }
    }
}
*/

using namespace std;

main()
{
    // JAY SHREE KRISHNA
    //int dp[100000][100000];

    int n;
    cin >> n;
    if(n)cout<<"0"<<endl;
    else cout<<"1"<<endl;

    return 0;
}
