#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  int K, N; cin >> K >> N;
  vi A(N); rep(i,N) cin >> A[i];
  vi B(N);
  rep(i, N-1){
    B[i] = A[i+1]-A[i];
  }
  B[N-1]=K-A[N-1]+A[0];
  int ans = 0;
  rep(i,N) ans = max(ans, B[i]);  
  cout << K-ans << endl;
  return 0;
}