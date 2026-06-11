#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define call(x) (x).cbegin(), (x).cend()
#define pb push_back
const double PI = acos(-1);
const long long INF = (1LL << 60);
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}
bool isInteger(double x){return floor(x) == x;}
ll ceil(const ll a, const ll b){return ((a)+(b)-1)/b;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, k, s;
  cin >> n >> k >> s;

  vector<ll> ans;
  for(ll i = 0; i < k; i++){
    ans.pb(s);
  }
  for(ll i = 0; i < n-k+1; i++){
    if(s == 1000000000) ans.pb(1);
    else ans.pb(1000000000);
  }

  for(ll i = 0; i < n; i++){
    cout << ans[i] << (i == n-1?'\n':' ');
  }
  return 0;
}