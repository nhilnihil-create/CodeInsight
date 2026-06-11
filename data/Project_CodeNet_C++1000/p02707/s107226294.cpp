#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  
  vector<int> joushi(N-1);
  for (int i=0; i<N-1 ;i++){
    cin >> joushi.at(i);
  }
  
   vector<int> buka(N);
   for (int i=0; i<N-1 ;i++){
     buka.at(joushi.at(i)-1) += 1;
   }
    
  for (int j=0; j<N ;j++){  
  cout << buka.at(j) << endl;
  }
  
  
  return 0;
}

