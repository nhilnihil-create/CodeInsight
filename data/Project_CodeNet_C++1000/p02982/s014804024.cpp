#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,D;
  cin >> N >> D;
  
  vector<vector<int>> matrix(N, vector<int>(D));
  for (int i=0; i<N; i++){
    for (int j=0; j<D; j++){
      cin >> matrix.at(i).at(j);
    }
  }
  
  int ans = 0;
  
  int distance_squared = 0;
  for (int i=0; i<N-1; i++){
    for (int j=i+1;j<N; j++){
      for(int k=0;k<D;k++){
        distance_squared +=  pow((matrix.at(i).at(k) - matrix.at(j).at(k)),2);
      }
      for(int l=1; l<130; l++){
        if(distance_squared  == l*l){
          ans++;
          break;
        }
      }
      distance_squared  = 0;
    }
  }
  
  cout << ans << endl;
}
