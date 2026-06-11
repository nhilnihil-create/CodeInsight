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
  ll n,a, dif = 0;
  cin >> n;
  rep(i,0,n){
    cin >> a;
    if(a != i+1) dif++;
  }
  if(dif <= 2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}