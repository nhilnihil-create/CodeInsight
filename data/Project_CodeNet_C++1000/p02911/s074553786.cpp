#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Q;
  long K;

  cin >> N >> K >> Q;
  vector<int> vec(N);
  for(int i=0;i<Q;++i){
    int A; cin >> A;
    vec.at(A-1) += 1;
  }

  for(int i=0;i<N;++i){
    if(K-Q+vec.at(i) > 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}
