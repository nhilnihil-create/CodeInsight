#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> W(N);
  for (int i = 0; i < N; i++){
    cin >> W[i];
  }
  
  int sum = 0;
  for (int i = 0; i < N; i++){
    sum += W[i];
  }
  
  int sum2 = 0;
  for (int i = 0; i < N; i++){
    sum2 += W[i];
    
    if (sum2 >= sum / 2.0){
      if (sum2 - (sum - sum2) <= (sum - sum2 + W[i]) - (sum2 - W[i])){
        cout << sum2 - (sum - sum2) << endl;
        return 0;
      }
      else{
        if ((sum - sum2 + W[i]) - (sum2 - W[i]) >= 0){
          cout << (sum - sum2 + W[i]) - (sum2 - W[i]) << endl;
          return 0;
        }
        else{
          cout << (sum2 - W[i]) - (sum - sum2 + W[i]) << endl;
          return 0;
        }
      }
    }
  }
}