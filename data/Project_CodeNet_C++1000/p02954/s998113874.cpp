#include <bits/stdc++.h>
using namespace std;

int main () {
  string S;
  cin >> S;
  int N = S.size();
  vector<int>count(N,0);
  int R = 0;
  int L = 0;
  
  for (int i = 0; i < N-1; i++) {
    if (S.at(i) == 'R'){
      R++;
    }
    else {
      L++;
    }
    if (i == N-2){
      if (S.at(i+1) == 'R'){
        R++;
      }
      else {
        L++;
      }
    }
    if (S.at(i) == 'L' && S.at(i+1) == 'R'){
      if ((R+L) % 2 == 0){
        count.at(i-L) = (R+L)/2;
        count.at(i-L+1) = (R+L)/2;
      }
      else if (R % 2 == 0){
        count.at(i-L) = (R+L)/2;
        count.at(i-L+1) = R+L - (R+L)/2;
      }
      else {
        count.at(i-L+1) = (R+L)/2;
        count.at(i-L) = R+L - (R+L)/2;
      }
      R = 0;
      L = 0;
    }
    else if (i == N-2){
      if ((R+L) % 2 == 0){
        count.at(i-L+1) = (R+L)/2;
        count.at(i-L+2) = (R+L)/2;
      }
      else if (R % 2 == 0){
        count.at(i-L+1) = (R+L)/2;
        count.at(i-L+2) = R+L - (R+L)/2;
      }
      else {
        count.at(i-L+2) = (R+L)/2;
        count.at(i-L+1) = R+L - (R+L)/2;
      }
    }
  }
  
  for (int i = 0; i < N; i++) {
    cout << count.at(i);
    if (i == N-1){
      cout << endl;
    }
    else {
      cout << ' ';
    }
  }
}
        
        
    