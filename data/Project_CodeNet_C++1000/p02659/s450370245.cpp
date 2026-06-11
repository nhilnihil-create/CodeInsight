#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll a;
  long double b;
  cin >> a >> b;
  b*=100;
  b+=0.00001;
  int c=b;
  ll ans=a*c;
  cout << ans/100;
}
