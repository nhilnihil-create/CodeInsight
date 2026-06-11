#include <bits/stdc++.h>
using namespace std;

int main(){
  char S[6];
  int i;
  for(i = 0; i < 6; i++){
    cin >> S[i];
  }
  if(S[2] == S[3] && S[4] == S[5]){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}