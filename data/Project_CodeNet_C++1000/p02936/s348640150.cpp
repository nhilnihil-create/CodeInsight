#include<iostream>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip>//setprecision
#include<math.h>
#include <functional>
#include<climits>
using namespace std;
#define ll  long long 
#define rep(i, n)        for(ll i=0; i<(ll)(n); ++i)
#define mod 1000000007
  //vector<ll>to[1000005];
  // ll dp[2000000];
 int gcd(int a, int b)
{
  if (a%b == 0)
{
return(b);
}
else
{
return(gcd(b,a%b));
}
}
  vector<ll>e(200002);
  vector<ll>d(200002);
    vector<vector<ll>>c(1000002);
    vector<vector<ll>>c2(1000002);
int dfs(ll a,ll b){
  ll ans=0;
  if(b!=-1)d[a]+=d[b];
  rep(i,c[a].size()){
    if(c[a][i]==b)continue;
    dfs(c[a][i],a);
  }
  return 0;
}
int main(){
  ll a,b,ans=0,x,y;cin>>a>>b;
  rep(i,a-1){
    cin>>x>>y;
    c[x-1].push_back(y-1);
    c[y-1].push_back(x-1);
  }
  rep(i,b){
   cin>>x>>y;
    d[x-1]+=y;
  }
  e[ans]=d[ans];
  //cout<<ans;
  dfs(0,-1);
  rep(i,a)cout<<d[i]<<" ";
}
