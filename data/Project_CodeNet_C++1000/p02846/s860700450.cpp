#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(x, y) x = max(x, y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  ll t1, t2; cin >> t1 >> t2;
  ll a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
  ll suma = a1 * t1 + a2 * t2, sumb = b1 * t1 + b2 * t2;
  if(suma == sumb){
    cout << "infinity\n";
    return 0;
  }
  if((a1 > b1 && suma > sumb) || (a1 < b1 && suma < sumb)){
    cout << 0 << endl;
    return 0;
  }
  if(suma < sumb){
    swap(a1, b1);
    swap(a2, b2);
    swap(suma, sumb);
  }
  ll sa = suma - sumb;
  ll hani = (b1 - a1) * t1;
  ll ans = 1 + (hani / sa) * 2;
  if(hani % sa == 0){
    ans--;
  }
  /*cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
  cout << suma << " " << sumb << endl;
  cout << hani << " "<< sa << endl;*/
  cout << ans << endl;

  return 0;
}
