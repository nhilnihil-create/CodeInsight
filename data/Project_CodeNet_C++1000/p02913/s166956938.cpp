#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<ld> vld;
typedef vector<string> vstr;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)
#define TS to_string
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define endl "\n"

ll INF = 1e9;
ll MOD = 1000000007;
ll LINF = 1e18;
ld EPS = 1e-9;
ld PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "Yes" << endl;}
void no(){ cout << "No" << endl;}

//-----------------------------------------

vll z_array(string &s){
  ll n = s.size();
  vll res(n,0);
  res[0] = n;

  ll i = 1, j = 0;
  while(i < n){
    while(i + j < n && s[j] == s[i + j]) j++;
    res[i] = j;

    if(j == 0){ i++; continue;}

    ll k = 1;
    while(k < j && k + res[k] < j){
      res[i + k] = res[k];
      k++;
    }

    i += k; j -= k;
  }

  return res;
}
//-----------------------------------------
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  ll n;
  string s;
  cin >> n >> s;
  ll ans = 0;
  for(ll i=0;i<n;i++){
    vll z = z_array(s);
    for(ll j=0;j<z.size();j++){
      if(j >= z[j]) ans = max(ans,z[j]);
    }
    ll m = s.size();
    s = s.substr(1,m-1);
  }

  cout << ans <<endl;


    
  return 0;
}

