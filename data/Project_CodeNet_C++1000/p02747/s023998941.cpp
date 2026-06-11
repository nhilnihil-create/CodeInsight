#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  bool flg=true;
  if(S.size()%2!=0){
    flg=false;
    cout << "No" << endl;
    return 0;
  }
  for(int i=0;i<S.size();i++){
    if(i%2==0){
      if(S[i]!='h')flg=false;
    }else{
      if(S[i]!='i')flg=false;
    }
  }
  if(flg)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}