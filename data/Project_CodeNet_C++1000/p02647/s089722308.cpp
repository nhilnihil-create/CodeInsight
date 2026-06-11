#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N,K;
  cin >> N >> K;
  vector<int> A(N,0);
  rep(i,N) cin >> A.at(i);
  rep(ki,K){
    vector<int> B(N+1,0);
    rep(i,N){
      int l = max(0, i-A.at(i));
      int r = min(i+A.at(i)+1,N);
      B.at(l)++; B.at(r)--;
    }
    rep(i,N) B.at(i+1) += B.at(i);
    if(A == B) break;
    A = B;
  }
  
  rep(i,N) cout << A.at(i) <<' ';
  cout << endl;
  
}