#include<bits/stdc++.h>
using namespace std;


int main(){
  
  char c;
  map<char, int> S;
  
  for(int i = 0; i < 4; i++){
    
    cin >> c;
    S[c]++;
  }
  if(S.size() == 2 && S[c] == 2){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}