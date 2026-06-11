#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int A = S.size();
  int count = 0;
  for(int i =0;i < A;i++){
    if(i % 2 == 0){
    if(S[i] != 'R' && S[i] != 'U' && S[i] != 'D'){
      count++;
      }
    }
    if(i % 2 == 1){
      if(S[i] != 'L' && S[i] != 'U' && S[i] != 'D'){
        count++;
      }
    }
  }
  if(count > 0){
    cout << "No" << endl;
  }
else{
cout << "Yes" << endl;
}
}
