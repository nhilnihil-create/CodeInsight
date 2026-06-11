#include <bits/stdc++.h>
using namespace std; 

int main(){
  string S;
  cin >> S;
  int sum=0;
  for(int i=0;i<S.size();i++){
    int A=S.at(i)-'0';
    sum+=A;
  }
  if(sum%9==0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}