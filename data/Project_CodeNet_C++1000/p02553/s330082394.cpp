#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll a,b,c,d,k;
  cin >> a >> b >> c >> d;
  k = max(a*c,a*d);
  k = max(k,b*c);
  k = max(k,b*d);
  cout << k << endl;
}