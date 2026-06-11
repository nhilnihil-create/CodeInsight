#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll a,b,n;

ll floor(ll N){
  ll fl1 = (a*N)/b;
  ll fl2 = N/b;
  ll ans = fl1-a*fl2;
  return ans;
}

int main(){
  cin >>a >>b >>n;
  ll ans = floor(min(b-1, n));
  cout << ans << endl;
  return 0; 
}