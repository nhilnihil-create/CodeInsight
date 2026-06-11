/* Author : Aaryan Srivastava ^__^ */ 
#include <bits/stdc++.h>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second   
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define repA(i,x,y) for(int i = (x) ; i <= (y) ; i++)
#define repD(i,x,y) for(int i = (x) ; i >= (y) ; i--)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define setval(a,val) memset(a,val,sizeof(a))
#define Randomize mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define trav(x , a) for(auto &x : a)
#define sz(a) ((int)a.size())
typedef long long ll ; 
#define int ll
using namespace std;

const int N = 1e5 + 5 ;
const int mod = 1e9 + 7 ;
const ll inf = 1e18 ;
const int SZ = 101 ;
const long double eps = 1e-9 ;

using namespace __gnu_pbds;
using ordered_set =  tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ;

typedef pair<int, int> pii; 
typedef pair<int , pii> ipii ;
typedef pair<pii , int> piii ; 
typedef unsigned long long ull ;
typedef long double ld;

ll po(ll x,ll y,ll p = mod) {ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}

string s;
int dp[N][15];
int get_dp(int len, int rem){
  if(len == s.length())  return (rem == 5);
  int& ans = dp[len][rem];
  if(~ans) return ans ;
  if(s[len] != '?'){
    int d = s[len] - '0';
    return ans = get_dp(len +  1, (10 * rem + d) % 13); 
  }
  else{
    ans= 0;
    for(int i = 0 ; i < 10 ; ++i){
      ans = (ans + get_dp(len + 1, (10 * rem + i) % 13)) % mod ;
    }
    return ans ;
  }
}

void solve()
{
  cin >> s;
  setval(dp , -1);
  cout << get_dp( 0  , 0);
}
     
int32_t main(int32_t argc, char *argv[])
{
    ios::sync_with_stdio(0);    
    cin.tie(0); cout.tie(0);
    int TC = 1, t = 0;
    //cin >> TC ;
    while(t++ < TC)
    {
        //cout << "Case #" << t << ": " ;
        solve();
        cout << "\n" ;
    }
    return 0;
}
