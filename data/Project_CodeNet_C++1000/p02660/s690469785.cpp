#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin >> N;
  int M = 0;
  vector<int>A(40,0);
  for (int i = 2; i <= 1000000; i++) {
    if (N % i == 0){
      for (int j = 0; j < 40; j++) {
        if (N % i == 0){
          A.at(M)++;
          N /= i;
        }
        else {
          M++;
          break;
        }
      }
    }
  }

  int count = 0;
  for (int i = 0; i < 40; i++) {
    if (A.at(i) >= 36){
      count += 8;
    }
    else if (A.at(i) >= 28){
      count += 7;
    }
    else if (A.at(i) >= 21){
      count += 6;
    }
    else if (A.at(i) >= 15){
      count += 5;
    }
    else if (A.at(i) >= 10){
      count += 4;
    }
    else if (A.at(i) >= 6){
      count += 3;
    }
    else if (A.at(i) >= 3){
      count += 2;
    }
    else if (A.at(i) >= 1){
      count += 1;
    }
  }
  
  if (N > 1000000){
    cout << count + 1 << endl;
  }
  else {
    cout << count << endl;
  }
}
        


