#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int n;
  cin >> n;
  
  int x, y, z;
  x= n%10;
  n /= 10;
  
  y= n%10;
  n /= 10;
  
  z= n %10;
  
  if(x !=7 && y !=7 && z !=7 )
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}