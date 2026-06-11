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
  vl x(n+1,0);
  vl y(n+1,0);
  vl z(n+1,0);
  ll ans=1;
  for(ll i=1;i<=n;i++){
    ll a;
    cin>>a;
    ll tmp=0;
    if(a==x[i-1])tmp++;
    if(a==y[i-1])tmp++;
    if(a==z[i-1])tmp++;
    ans*=tmp;
    ans%=MOD;
    if(a==x[i-1]){
      x[i]=x[i-1]+1;
      y[i]=y[i-1];
      z[i]=z[i-1];
    }
    else if(a==y[i-1]){
      x[i]=x[i-1];
      y[i]=y[i-1]+1;
      z[i]=z[i-1];
    }
    else if(a==z[i-1]){
      x[i]=x[i-1];
      y[i]=y[i-1];
      z[i]=z[i-1]+1;
    }
    //cout<<x[i]<<" "<<y[i]<<" "<<z[i]<<endl;
  }
  print(ans);
}
