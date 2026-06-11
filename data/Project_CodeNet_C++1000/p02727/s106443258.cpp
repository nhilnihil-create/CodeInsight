#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace(x) cout << #x << ": " << x << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define INF 1LL<<62

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const ll MAX =1e7 +10;
int main(){
  ll x, y, a, b, c;
  scanf("%lld %lld %lld %lld %lld", &x, &y,&a,&b,&c);
  vi arr1(a);
  vi arr2(b);
  vi arr3(c);
  rep(i,0,a) scanf("%lld", &arr1[i]);
  rep(i,0,b) scanf("%lld", &arr2[i]);
  rep(i,0,c) scanf("%lld", &arr3[i]);
  sort(all(arr1));
  sort(all(arr2));
  sort(all(arr3));
  vi aux;
  rep(i,0,x) aux.pb(arr1[a-i-1]);
  rep(i,0,y) aux.pb(arr2[b-i-1]);
  rep(i,0,c) aux.pb(arr3[i]);
  sort(all(aux));
  ll rpta = 0;
  rep(i,0,x+y) rpta+=aux[aux.size()-1-i];
  printf("%lld\n", rpta);
}