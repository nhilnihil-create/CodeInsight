#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll a = 0,b = 0;
  cin >> a >> b;
  a = a - b*2;
  if(a < 0){
    cout << 0;
  }
  else{
    cout << a;
  }
}