#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int>A(9);
  vector<int>B(10);
  int N;
  for(int i =0; i<9; i++){
    cin >> A.at(i);
  }
  
  cin >> N;
  
  for(int i=0; i<N; i++){
    cin >> B.at(i);
  }
  
  string ans = "No";
  
  for(int i=0; i<9; i++){
    for(int j=0; j<N; j++){
      if(A.at(i)==B.at(j)){
        A.at(i) = 0;
      }
    }
  }
  
  if(A.at(0) == 0 && A.at(1) ==0 && A.at(2) == 0){ans = "Yes";}
  if(A.at(3) == 0 && A.at(4) ==0 && A.at(5) == 0){ans = "Yes";}
  if(A.at(6) == 0 && A.at(7) ==0 && A.at(8) == 0){ans = "Yes";}
  
  if(A.at(0) == 0 && A.at(3) ==0 && A.at(6) == 0){ans = "Yes";}
  if(A.at(1) == 0 && A.at(4) ==0 && A.at(7) == 0){ans = "Yes";}
  if(A.at(2) == 0 && A.at(5) ==0 && A.at(8) == 0){ans = "Yes";}
  
  if(A.at(0) == 0 && A.at(4) ==0 && A.at(8) == 0){ans = "Yes";}
  if(A.at(2) == 0 && A.at(4) ==0 && A.at(6) == 0){ans = "Yes";}
  
  cout << ans << endl;
  
}