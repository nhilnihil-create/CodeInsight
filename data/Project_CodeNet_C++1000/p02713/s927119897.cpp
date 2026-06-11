#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

template<typename T>
T gcd(T a, T b) {
  if(a < b) swap(a,b);
    
  if(b == 0) return a;
  return gcd(b, a % b);
}


int main(){
  cout << setprecision(10);

  ll K; cin >> K;

  ll ans = 0;
  for(ll i = 1; i <= K; i++){ 
    for(ll j = i; j <= K; j++){ 
      for(ll k = j; k <= K; k++){ 

        ll tmp = gcd(i, gcd(j,k));
        if(i == j && j == k){
          ans += tmp;
        } else if(i == j || j == k){
          ans += tmp * 3;
        } else { 
          ans += tmp * 6;
        }
      }
    }
  }
  cout << ans << endl;
}
