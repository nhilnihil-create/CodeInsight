#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main() {
  ll a ; cin >> a;
  double b; cin >> b;
  ll c = b*100 + 0.5;
  ll ans = a * c / 100 ;
  
  cout << ans << endl;
}
      
