#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  ll a,b,k;
  cin >> a >> b >> k;
  if(k <= a) a = a-k;
  else if(k <= a + b){
    b = b - k + a;
    a = 0;
  }
  else{
    a = 0;
    b = 0;
  }
  cout << a << " " << b << endl;
}