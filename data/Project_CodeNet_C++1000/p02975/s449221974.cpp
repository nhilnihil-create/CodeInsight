#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
  ll n;
  cin>>n;
  vl a(n);
  ll count = 0;
  bool z = true;
  rep(i, n){
    cin >> a[i];
    if(a[i]==0){
      count++;
    }
  }
  if(count==n){
    print("Yes");
    return 0;
  }
  else if (n % 3 != 0){
    print("No");
    return 0;
  }
  sort(all(a));
  ll c = a[0] ^ a[n / 3] ^ a[n - 1];
  if (count == n / 3 && a[n / 3] == a[n - 1]){
    print("Yes");
  }
  else if(a[0]==a[n/3-1]&&a[n/3]==a[n/3*2-1]&&a[n/3*2]==a[n-1]&&a[0]!=a[n/3]&&a[n/3]!=a[n/3*2]&&c==0){
    print("Yes");
  }
  else{
    print("No");
  }
}
