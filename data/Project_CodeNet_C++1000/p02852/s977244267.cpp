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
  ll n,m;
  cin >> n >> m;
  string s;
  cin >> s;
  vl a(n+1,0);
  ll k=n,r=k;
  ll i=0;
  bool can=true;
  ll sum=0;
  while(sum<n){
    k -=m;
    while(k<0||s[k]=='1'){
      k++;
      if(k==r){
        can =false;
      }
    }
    if(!can){
      break;
    }
    a[i]=r-k;
    r=k;
    sum +=a[i];
    i++;
  }
  if(!can){
    cout << -1 << endl;
  }
  else{
    for(int i=n;i>=0;i--){
      if(a[i]!=0){
        cout << a[i] << " ";
      }
    }
  }
}