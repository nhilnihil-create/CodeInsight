#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

void dfs(ll n,string s,ll lim) {
  if(n==0) {
    cout << s << endl;
  }
  else {
    for(ll i=0;i<=lim;i++) {
      char tmp='a'+i;
      if(i!=lim) {
        dfs(n-1,s+tmp,lim);
      }
      else {
        dfs(n-1,s+tmp,lim+1);
      }
    }
  }
}

int main() {
  ll n;
  cin >> n;
  string s="a";
  dfs(n-1,s,1);
}