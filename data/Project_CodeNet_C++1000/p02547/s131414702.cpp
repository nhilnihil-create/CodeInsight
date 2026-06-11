#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define f first
#define s second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;

int main(){ _
  lli n;
  cin >> n;
  lli c = 0;
  fore (i,0,n){
    if (c == 3){
      cout << "Yes" << ENDL;
      return 0;
    }
    else{
      lli x, y;
      cin >> x >> y;
      if (x == y){
        c++;
      }
      else{
        c = 0;
      }
    }
  }
  if (c == 3){
    cout << "Yes" << ENDL;
  }
  else{
    cout << "No" << ENDL;
  }
  return 0;
}
