#include <bits/stdc++.h>
using namespace std;

int main() {
  long long H,N,X=0;
  cin >> H >> N;
  vector<long long>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
    X += vec[i];
  }
  if(X<H){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}
