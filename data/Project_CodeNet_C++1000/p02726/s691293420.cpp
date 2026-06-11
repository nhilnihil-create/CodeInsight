#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> 
//using boost::multiprecision::cpp_int;
using namespace std;
#define ll long long int
#define F first
#define S second
//#define endl "\n"
//#define nl cout<<endl;
#define pb push_back
#define ull unsigned long long 
#define f(i,a,b) for(ll i=a;i<b;i++)
#define Knucklehead ios_base::sync_with_stdio(false);cin.tie(NULL);
//#define mod 100000007
#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.second > b.second )
        return true;
    if( a.second==b.second && a.first > b.second )
       return true;
    return false;
}
bool cmp(int n, pair<int, int> const& p)
{
    return (p.first < n);
}
//me
ll const mod = 1e9+7;//998244353;
ll const inf = 1e18;
ll const maxn = 2e3+1;
ll tc[maxn][maxn];
ll dis[maxn][maxn];
vector<ll> nodes[maxn];
void bfs(ll x)
{
     tc[x][x]=1;
     queue<ll> q;
     q.push(x);

     while(!q.empty())
     {
          ll cur = q.front();
          q.pop();

          for(auto ch : nodes[cur]){
               if(tc[x][ch]==0){
                    tc[x][ch]=1;
                    dis[x][ch]=dis[x][cur]+1;
                    q.push(ch);
               }
          }
     }
}
void solve()
{    

     ll n,x,y;
     cin >> n >> x >> y;

     f(i,1,n)
          nodes[i].pb(i+1), nodes[i+1].pb(i);

     nodes[x].pb(y);
     nodes[y].pb(x);

     for(ll i=1; i<=n; i++)
          bfs(i);
     map<ll,ll> cnt;
     f(i,1,n+1)
          f(j,1,n+1)
               cnt[dis[i][j]]++;   

     f(i,1,n)
          cout << cnt[i]/2 << endl;

     
}

int main() {
Knucklehead 
//*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
/**/ 
          
          ll t;
          /**/t=1;
          /*/cin>>t;/**/
          f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
          }
 
 
    return 0;
}