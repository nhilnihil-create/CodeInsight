#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(n) n.begin(),n.end()
#define yn(x) cout << (x ? "Yes":"No") << endl;


int main() {
  ll a,b,c;
  cin >> a >> b >> c;
  yn(c-a-b>0 && 4*a*b<(c-a-b)*(c-a-b));
}
