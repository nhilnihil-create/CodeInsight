#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int N;
  cin >> N;
  rep(i,N){
    int A;
    cin >> A;
    if(A % 2 == 0){
      if(A % 3 != 0 && A % 5 != 0){
        cout << "DENIED" << endl;
        return 0;
      }
    }
  }
  cout << "APPROVED" << endl;
  return 0;
}

