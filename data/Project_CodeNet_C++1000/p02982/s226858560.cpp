#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N,D;
  cin >> N >> D;
  
  vector<vector<int>> X(N, vector<int>(D));
  for(int i=0; i<N; i++){
    for(int j=0; j<D; j++){
      cin >> X.at(i).at(j);
    }
  }
  
  int ans=0;
  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      int norm = 0;
      for(int k=0; k<D; k++){
        int diff = X.at(i).at(k) - X.at(j).at(k);
        norm += diff * diff;
      }  
      
      for(int k=0; k <= norm; k++){
        if(k*k == norm){
          ans++;
        }
      }
    
    }
  }

  cout << ans << endl;
  
  
  
}