#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  int N,x; cin >> N >> x;
  int ans = 1;
  int dist = 0;
  vector<int>A(N);
  rep(i,N){
    cin >> A[i];
  }
  rep(i,N){
    dist += A[i];
    if(dist <= x){
      ans++;
    }
  }
  cout << ans;
}
    