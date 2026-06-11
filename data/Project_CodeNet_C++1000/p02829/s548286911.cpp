#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int a,b;
  cin >> a >> b;
  
  for(int i=1;i<4;i++){
    if(i != a && i != b)
      cout << i << endl;
  }
}