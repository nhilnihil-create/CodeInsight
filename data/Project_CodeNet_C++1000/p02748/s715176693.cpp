#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  ll A, B, M;
  cin >> A >> B >> M;
  vector<ll> a(A+1), b(B+1);
  ll mn_a = pow(10,6), mn_b = pow(10,6);
  for(ll i=1; i<=A; ++i){
    cin >> a[i];
    mn_a = min(a[i], mn_a);
  }
  for(ll i=1; i<=B; ++i){
    cin >> b[i];
    mn_b = min(b[i], mn_b);
  }

  vector<ll> x(M+1), y(M+1), c(M+1);
  for(ll i=1; i<=M; ++i) cin >> x[i] >> y[i] >> c[i];
  
  ll ans;
  ll mn_ans = a[1] + b[1];
  for(ll i=1; i<=M; ++i){
    ans = a[x[i]] + b[y[i]] - c[i];
    mn_ans = min(ans, mn_ans);
  }
  
  ll ans1 = min(mn_ans, mn_a + mn_b);
  cout << ans1 << endl;
  return 0;
}