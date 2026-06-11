#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
 
  vector<int>x(N);
  vector<int>y(N);
  for (int i = 0; i < N; i++){
    cin >> x.at(i) >> y.at(i);
  }
  
  if (N == 1 || N == 2){
    cout << 1 << endl;
    return 0;
  }
      
  vector<int>count(N*(N-1)/2);
  int M = 0;
  for (int i = 0; i < N-1; i++){
    for (int j = i+1; j < N; j++){
      int X = x.at(i) - x.at(j);
      int Y = y.at(i) - y.at(j);
      if (X == 0 && Y == 0){
        M++;
        break;
      }
      for (int k = 0; k < N-1; k++){
        for (int l = k+1; l < N; l++){
          if (x.at(k) - x.at(l) == X && y.at(k) - y.at(l) == Y){
            count.at(M)++;
          }
          else if (x.at(l) - x.at(k) == X && y.at(l) - y.at(k) == Y){
            count.at(M)++;
          }
        }
      }
      M++;
    }
  }
  sort(count.begin(), count.end());
  reverse(count.begin(), count.end());
  
  cout << max(1,N-count.at(0)) << endl;
}
  
    
  
    