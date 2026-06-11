

#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N,D;
  cin >> N >> D;
  int result = 0;
  double count = 0;
  vector<vector<double>> A(N,vector<double>(D));
  for(int a = 0;a < N;a++){
   for(int b = 0;b < D;b++){
     cin >> A[a][b];
     
   }
  }
  for(int a = 0;a < N;a++){
    for(int b = a + 1;b < N;b++){
      count = 0;
      for(int c = 0;c < D;c++){
       count += (A[a][c] - A[b][c]) * (A[a][c] - A[b][c]);
      }
      count = sqrt(count);
      int d = count;
      if(d == count)result++;
      
    }
  }
  cout << result << endl;
}