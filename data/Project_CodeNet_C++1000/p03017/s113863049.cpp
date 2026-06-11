#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B,C,D;
  cin >> N >> A >> B >> C >> D;
  string S;
  cin >> S;
  for(int i=A;i<C-2;i++){
    if(S.substr(i,2)=="##"){
      cout << "No" << endl;
      return 0;
    }
  }
  for(int i=B;i<D-2;i++){
    if(S.substr(i,2)=="##"){
      cout << "No" << endl;
      return 0;
    }
  }
  if(C<D){
    cout << "Yes" << endl;
  }else{
    for(int i=B-2;i<D-1;i++){
      if(S.substr(i,3)=="..."){
        cout << "Yes" << endl;
        return 0;
      }
    }
    cout << "No" << endl;
  }
  return 0;
}
