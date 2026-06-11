#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<string,int>;
using T = tuple<string,int,int>;

int main(){
  ll a,b,c;
  cin >> a >> b >> c;
  ll x = c-a-b;
  if(x < 0){
    cout << "No" << endl;
    return 0;
  }
  if(4*a*b < x*x) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
