#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  vector<ll> A(n,0),K(n);
  
  rep(i,n){
    cin >> K[i];
    A[K[i]-1]++;
  }
  ll cnt = 0;
  vector<ll> B(n);
  rep(i,n){
    B[i] = A[i]*(A[i]-1)/2;
    cnt += B[i];
  }
  // cntは全ての組み合わせの総和
  
  
  rep(i,n){
    if(A[K[i]-1] != 0)
      cnt += - B[K[i]-1] + (A[K[i]-1]-1)*(A[K[i]-1]-2) / 2;
    cout << cnt << endl;
    if(A[K[i]-1] != 0)
      cnt +=  B[K[i]-1] - (A[K[i]-1]-1)*(A[K[i]-1]-2) / 2;
  }
}