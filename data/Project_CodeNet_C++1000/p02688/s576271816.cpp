#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, K;
  cin >> N >> K;
  int d;
  vector<int> A(N);
  int x;
  rep(i, K){
   cin >> d;
   rep(j, d){
    cin >> x; 
    A.at(x-1)++;
   }
  }
  int ans = 0;
  rep(i, N){
   if(A.at(i) == 0) ans++; 
  }
  cout << ans << endl;
  return 0;
}