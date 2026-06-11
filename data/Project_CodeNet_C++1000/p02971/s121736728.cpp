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
  
  vector<int> right(N);
  vector<int> left(N);
  
  for(int i=1; i<N; i++) left.at(i) = max(left.at(i-1), A.at(i-1));
  for(int i=N-2; i>=0; i--) right.at(i) = max(right.at(i+1), A.at(i+1));
  
  rep(i, N) cout << max(left.at(i), right.at(i)) << endl;
  
  return 0;
}


