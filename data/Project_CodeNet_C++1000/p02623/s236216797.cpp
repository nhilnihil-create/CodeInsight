#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }


int main() {
  ll N, M, K;
  cin >> N >> M >> K;

  vector<ll> A(N), B(M);

  for(ll i = 0; i < N; i++) {
    cin >> A[i];
  }

  for(ll i = 0; i < M; i++) {
    cin >> B[i];
  }

  vector<ll> sa(N + 1), sb(M + 1);

  for(ll i = 0; i < N; i++) {
    sa[i + 1] = A[i] + sa[i];
  }

  for(ll i = 0; i < M; i++) {
    sb[i + 1] = B[i] + sb[i];
  }
    
    ll ans = 0;
    ll j = M;
    ll max = M;
  for(ll i = 0; i < N + 1; i++) {
      
      while(sa[i] + sb[j] > K) {
        j--;
        if(j < 0) { j = max; break; }
      }
      if(sa[i] + sb[j] <= K) {
         max = j; 
        if(ans < i + j) ans = i + j;
         }
      
      
  }


  cout << ans;
  

  return 0;
}