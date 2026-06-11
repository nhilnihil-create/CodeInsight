#include<iostream>
using namespace std;

int main() {
  string S;
  cin>>S;
  int C=0,c=0,i;
  for (i=0;i<S.size();i++) {
    if (S[i]=='R') {
      c++;
      C = max(C, c);
    }
    else c=0;
  }
  cout<<C<<endl;
  return 0;
}
