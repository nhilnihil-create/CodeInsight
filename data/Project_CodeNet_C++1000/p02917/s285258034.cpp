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
  int N; cin >> N;
  vi a(N); vi b(N-1);
  rep(i,N-1) cin >> b[i];
  a[0] = b[0];
  rep2(i,1,N){
    a[i] = b[i-1];
    if(a[i-1] > b[i-1]) a[i-1] = b[i-1];
  }
  int ans = 0;
  rep(i,N) ans += a[i];
  cout << ans << endl; 
  return 0;
}