#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i)
#define rep2(i,a,n) for(int i=(a); i<(n); ++i)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  ll N, A, B; cin >> N >> A >> B;
  ll ans;
  if((B-A)%2 == 0) ans = (B-A)/2;
  else{ //ans = min(B-1, N-A);  
  ll t = min(N-B, A-1);
    if(t == N-B){B = N; A = A+(t+1);}
    else { A = 1; B =B-(t+1);}
    ans = t+1 + (B-A)/2;
  }
  cout << ans << endl;  
  return 0;

}