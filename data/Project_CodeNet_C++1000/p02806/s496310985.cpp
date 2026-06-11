#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
 
#if DEBUG
    #include "debug.h"
#else
    #define debug(args...)
#endif    

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;


#define M 1000000 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define fill(a,x) memset(a,x,sizeof(a))
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = INT_MAX;
const int mod = 1e9+7;

const int N = 2e5 + 10;
inline int add(int x,int y){
  x += y;
  if(x >= mod) x -= mod;
  return x;
}
inline int mul(int x,int y){
  x = (1LL * x * y) % mod;
  return x;
}
clock_t time_p=clock();



int32_t main(){
  fast;

  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);

  int n;
  cin >> n;
  vector<pair<string,int>>v(n);
  FOR(i,0,n-1)cin >> v[i].F >> v[i].S;
  string x;
  cin >> x;
  int ans = 0;
  int ff = 0;
  FOR(i,0,n-1) {
    if(ff)ans += v[i].S;
    if(v[i].F == x)ff = 1;
  }  
  cout << ans;

  time_p=clock()-time_p;
  cerr<<"\nTime Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";

  return 0;
}