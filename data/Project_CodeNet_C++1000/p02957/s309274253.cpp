#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define ff first
#define ss second
#define fill(x,v) memset(x, v, sizeof(x))


typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

vi arr;

int main(){
  ll a,b;
  cin >> a >> b;
  ll suma = a+b;
  if(suma%2) cout << "IMPOSSIBLE" << endl;
  else{
  ll rpta = suma/2;
  cout << rpta << endl;
  }
  return 0;
}