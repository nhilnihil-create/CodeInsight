#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define YY cout << "Yes" << endl;
#define NN cout << "No" << endl;
#define ve vector
#define pint pair<int,int>
const int INF = 1000000007;
const long double EPS = 1e-15;
const long double PI = acos(-1);
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
// *max_element(all(d))
// priority_queue<int,vector<int>,greater<int>>
ll ss(string s){
  ll cnt = 0,res = 0;
  rep(i,s.size()){
    cnt++;
    if(i == (int)s.size() - 1 || s[i] != s[i + 1]){
      res += cnt / 2;
      cnt = 0;
    }
  }
  return res;
}
int solve(){
  string s;
  cin >> s;
  int k;
  cin >> k;
  bool f = true;
  rep(i,s.size() - 1)if(s[i] != s[i + 1])f = false;
  if(f){
    ll size = (ll)s.size() * k;
    cout << size / 2 << endl;
  }
  else{
    string V1 = s;
    string V2 = s + s;
    ll R1 = ss(V1),R2 = ss(V2);
    cout << R1 + (R2 - R1) * (k - 1) << endl;
  }
  return 0; 
}
int main(){
  // ios::sync_with_stdio(false);cin.tie(nullptr);
  // cout << fixed;cout << setprecision(16);
  solve();
  return 0;
}