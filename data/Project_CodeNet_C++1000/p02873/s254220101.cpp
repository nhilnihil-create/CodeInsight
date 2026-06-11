#include <bits/stdc++.h>
using namespace std;

int main(){
  string S; cin >> S;
  
  // >>...><...<<のセットで考える
  long long result=0;
  long long l=0, r=0;
  for(int i=0; i<S.size(); i++){
    (S[i]=='>'?l:r)++;
    
    if(i==S.size()-1){
      if(S[i]=='<'){
        result+=(r*(r+1)/2);
      }else{
        result+=(l*(l+1)/2);
        result-=min(l,r);
      }
    }else if(S[i]=='<'&&S[i+1]=='>'){
      result+=(r*(r+1)/2);
      l=0;
    }else if(S[i]=='>'&&S[i+1]=='<'){
      result+=(l*(l+1)/2);
      result-=min(l,r);
      r=0;
    }
  }
  cout << result << endl;
}