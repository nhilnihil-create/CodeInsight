#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
 
  vector<long long>A(N);
  vector<long long>B(N);
  B.at(0) = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (i != 0){
      if (A.at(i) > A.at(i-1)){
        B.at(i) = 1;
      }
      else if (A.at(i) < A.at(i-1)){
        B.at(i) = -1;
      }
      else {
        B.at(i) = 0;
      }
    }
  }
  
  long long money = 1000;
  long long kabu = 0;
  for (int i = 0; i < N; i++) {
    if (i == 0){
      if (B.at(i+1) > B.at(i)){
        kabu += money / A.at(i);
        money = money % A.at(i);
      }
    }
    else if (i != N-1){
      if (B.at(i-1) <= B.at(i) && B.at(i) > B.at(i+1)){
        money += kabu * A.at(i);
        kabu = 0;
      }
      else if (B.at(i-1) >= B.at(i) && B.at(i) < B.at(i+1)){
        kabu += money / A.at(i);
        money = money % A.at(i);
      }
    }
    else {
      money += kabu * A.at(i);
      kabu = 0;
    }   
  }
  long long C = 1000;
  cout << money << endl;
}
      
        
      


