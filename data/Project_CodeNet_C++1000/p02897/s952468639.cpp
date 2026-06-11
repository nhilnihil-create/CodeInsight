#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
using ll = long long;
int main(){
  double a;
  cin >> a;
  if(a == 1)cout << fixed << setprecision(12) << 1.000000000000 << endl;
  else {
    int wa = a/2;
    if(fmod(a,2) == 1)wa++;
    double res = double(wa/a);
    cout << fixed << setprecision(12) << res << endl;
  }
  return 0;
}
