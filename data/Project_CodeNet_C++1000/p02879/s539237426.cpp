#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll a = 0,b = 0;
  cin >> a >> b;
  if(a > 9 || b > 9){
    cout << -1;
  }
  else{
    cout << a*b;
  }
}