#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  int r = 0;
  cin >> S;
  
    if(S[0] == 'R' && S[1] == 'R' && S[2] == 'R' ){
      r=3;
    }else if((S[0] == 'R' && S[1] == 'R') ||(S[1] == 'R' && S[2] == 'R')){
      r=2;
    }else if(S[0] == 'R' || S[1] == 'R' || S[2] == 'R'){
      r=1;
    }
  cout << r << endl;
      
  return 0;
}
