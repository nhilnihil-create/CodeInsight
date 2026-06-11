#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;cin >> S;
  int N = S.size();
  if(N%2>0){
    cout << "No" << endl;
    return 0;
  }
  for(int i=0;2*i<N;i++){
    if(S[2*i]!='h'||S[2*i+1]!='i'){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}