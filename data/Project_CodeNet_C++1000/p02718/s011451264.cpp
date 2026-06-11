#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int N,M;
  cin >> N >> M;
  vector<int> A(N);
  int sum = 0;
  rep(i,N){
    cin >> A.at(i);
    sum += A.at(i);
  }
  sort(A.begin(),A.end());
  if(A.at(N - M)*4*M >= sum){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}