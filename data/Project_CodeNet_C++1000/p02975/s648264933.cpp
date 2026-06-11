#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll n;
  cin >> n;
  vl a(n);
  rep(i,n){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  ll r=a[0]^a[n/3]^a[2*n/3];
  if(a[n-1]==0){
    cout << "Yes" << endl;
  }
  else if(n%3==0&&(a[0]==a[n/3-1]&&a[n/3]==a[2*n/3-1]&&a[2*n/3]==a[n-1])&&r==0){
    cout << "Yes" << endl;
  }
  else
    cout << "No" << endl;
}