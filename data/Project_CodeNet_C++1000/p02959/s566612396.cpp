#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n;
  cin >> n;
  int a[n+1], b[n];
  for(int i=0; i<n+1; ++i) cin >> a[i];
  for(int i=0; i<n; ++i) cin >> b[i];
  ll ans = 0;
  for(int i=0; i<n; ++i){
    ll res = min(a[i], b[i]);

    ans += res;
    a[i] -= res;
    b[i] -= res;

    ll res1 = min(a[i+1], b[i]);

    ans += res1;
    a[i+1] -= res1;
    b[i] -= res1;

  }
  cout << ans << endl;
}