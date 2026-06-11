#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N){
    cin >> A.at(i);
  }
  
  vector<int> B = A;
  sort(B.begin(), B.end());
  
  
  rep(i, N){
    if(B.at(N-1) != A.at(i)) cout << B.at(N-1) << endl;
    else cout << B.at(N-2) << endl;
  }
  
  
  
  return 0;
}


