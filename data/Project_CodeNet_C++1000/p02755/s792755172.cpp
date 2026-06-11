//FIRST THINK THEN CODE.

#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

#define rep(i,a,b) for(ll i=a;i<b;++i)
#define rrep(i,a,b) for(ll i=a;i>b;--i)
#define FOR(i,n)  for(ll i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define vld vector<ld>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vvld vector<vector<ld>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define PI 3.1415926535897932384626433832795
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()
#define rev(p) reverse(p.begin(),p.end());
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define popcount(x) __builtin_popcountll(x)
#define sz(x) ((ll)x.size())
const ll M = 1000000007;
const ll MM = 998244353;
ll begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define trace(...)
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

template<typename T, typename F>
void chmax( T &a, F b) {
  if (b > a)a = b;
}

template<typename T, typename F>
void chmin( T &a, F b) {
  if (b < a)a = b;
}



ll powM(ll a, ll b, ll m)
{
  if (a <= 0)return 0;
  a %= m;
  ll ans = 1LL;
  while (b)
  {
    if (b & 1)ans = ans * a % m;
    a = a * a % m;
    b >>= 1;
  }

  return ans;
}



ll poww(ll a, ll b)
{

  ll ans = 1;
  while (b)
  {
    if (b & 1)ans = ans * a;
    a = a * a;
    b >>= 1;
  }

  return ans;

}


string tostring(ll x) {
  stringstream sss;
  sss << x;
  string ans = sss.str();
  return ans;
}



const ll N = 1e6 + 5;


/* we are looking for non-zero suffixes,

a2 a1 a0

// so wee need to store the information regarding last digit so far

bcz it can be zero and then if next digit is non zero,then this needs to be taken into account.

eg : 0 --> NO
    30 --> YES

dp[n][k][par],if cur digit is zero ,then par =0,else par=1.

dp[i][l+(10^i)*p][(p!=0)]+=dp[i-1][l][].

.lets take an example  with n=5 and k=3.

dp[0][0][1]=3,dp[0][0][0]=1;

dp[1][]


*/


int main() {

  IOS;

#ifndef ONLINE_JUDGE

  freopen("input1.txt", "r", stdin);
  freopen("output1.txt", "w", stdout);

#endif


  ll a, b;
  cin >> a >> b;

  for (ll i = 1; i <= 10000; i++) {
    ll y = (8 * i) / 100;
    ll z = i / 10;
    if (y == a && z == b) {
      cout << i;
      return 0;
    }
  }
  cout << -1;

  return 0;
}