#include <bits/stdc++.h>
using namespace std;
 
using ll = int64_t;
constexpr ll mod = ll(1e9 + 7);
 
int main () {
  ios::sync_with_stdio(0); cin.tie(0);
 

  ll a,b,c;
  cin >> a >> b >> c;
  swap(a,b);
  swap(a,c);
  cout << a <<  " " << b << " "  << c << endl;

}
