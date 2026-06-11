#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef bool bl;
typedef vector<bl> vb;
typedef vector<vl> mt;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<string> vs;
typedef vector<vs> table;
typedef vector<vl> v2;
typedef vector<v2> v3;
typedef vector<v3> v4;


const ll e5 = 1 << 20;
const ll mod = 1000000007;
const ll e3 = 1 << 13;
const ll INF = 1ll << 50;

ll n;
mt a;

int main(){
  cin >> n;
  a = mt(n,vl(n));
  for(ll i = 0;i < n;i++){
    for(ll j = i+1;j < n;j++){
      ll x = i^j;
      ll k = 1;
      while(x%2 == 0){
        x /= 2;
        k++;
      }
      a[i][j] = a[j][i] = k;
    }
  }
  for(ll i = 0;i < n;i++){
    for(ll j = i+1;j < n;j++){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

}
