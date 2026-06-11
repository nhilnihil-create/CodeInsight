#include<bits/stdc++.h>
using namespace std;

int main(){
  string S,T;
  cin >> S >> T;
  int A=S.size();
  T=T.substr(0,A);
  if(S==T){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
