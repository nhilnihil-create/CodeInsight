#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  
  vector<long long>H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  
  for (int i = 0; i < N-1; i++) {
    if (H.at(i) > H.at(i+1)){
      cout << "No" << endl;
      return 0;
    }
    else if (H.at(i) <= H.at(i+1) - 1){
      H.at(i+1)--;
    }
  }
  
  cout << "Yes" << endl;
}
 