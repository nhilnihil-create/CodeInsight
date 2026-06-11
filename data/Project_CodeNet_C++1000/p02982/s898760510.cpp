#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,D;
  cin >> N >> D;
 
  vector<vector<int>> data(N, vector<int>(D));
 
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) {
      cin >> data.at(i).at(j);
    }
  }
  
  int d = 0;
  int count = 0;
   for (int i = 0; i < N-1; i++) {
     for (int k = i+1; k < N; k++) {
       for (int j = 0; j < D; j++) {
         d += (data.at(k).at(j) - data.at(i).at(j))*(data.at(k).at(j) - data.at(i).at(j));
       }
       for (int l = 0; l < 128; l++) {
         if (l*l == d){
           count++;
           break;
         }
       }
     d = 0;
     }
   }
  cout << count << endl;
}
  