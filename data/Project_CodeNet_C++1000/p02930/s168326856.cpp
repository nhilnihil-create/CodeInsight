#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n;
  cin >> n;
  for(ll i=0;i<n-1;i++,cout<<endl) {
    for(ll j=i+1;j<n;j++) {
      ll t=1,x=i,y=j;
      while((x&1)==(y&1)) x>>=1,y>>=1,t++;
      cout << t << " ";
    }
  }
}