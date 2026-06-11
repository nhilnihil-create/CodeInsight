#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A,B;
  cin >> A >> B;
  int j = 0;
  int i = 2;
  
  vector<int>a(40,0);
  while (A > 1){
    if (A % i == 0){
      for (int k = 0; k < 40; k++) {
        if (A % i == 0){
          A = A/i;
        }
        else {
          a.at(j) = i;
          j++;
          break;
        }
      }
    }
    else {
      i++;
      if (i > 1000000){
        A *= -1;
      }
    }
  }
  
  j = 0;
  i = 2;
  vector<int>b(40,0);
  while (B > 1){
    if (B % i == 0){
      for (int k = 0; k < 40; k++) {
        if (B % i == 0){
          B = B/i;
        }
        else {
          b.at(j) = i;
          j++;
          break;
        }
      }
    }
    else {
      i++;
      if (i > 1000000){
        B *= -1;
      }
    }
  }
  
  int count = 1;
  
  if (A < 1 && A == B){
    count++;
  }
  
  for (int k = 0; k < 40; k++) {
    for (int l = 0; l < 40; l++) {
      if (a.at(k) > 1 && a.at(k) == b.at(l)){
        count++;
      }
    }
  }
  cout << count << endl;
}


