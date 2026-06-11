#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
  ll a,b,k;
  cin >> a >> b >> k;
  if(a>=k){
    a-=k;
    cout << a << " " << b << endl;
  }
  else {
    k-=a;
    a=0;
    b-=k;
    if(b<0)b=0;
    cout << a << " " << b << endl;
  }
}
