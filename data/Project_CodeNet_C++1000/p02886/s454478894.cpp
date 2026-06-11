#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> T(N);
  for(int i=0;i<N;i++) cin >> T.at(i);
  
  int Ans=0;
  
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      Ans += T.at(i)*T.at(j);
    }
  }
  
  for(int i=0;i<N;i++){
    Ans -= T.at(i) * T.at(i);
  }
  
  Ans /= 2;
  
  cout << Ans << endl;
}
