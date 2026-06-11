#include<iostream>
using namespace std;

char move(char s,int n){
  if (s+n>90) return char(s+n-26);
  else return char(s+n);
}
main(){
  int N;
  string s;
  cin>>N;
  cin>>s;
  for(int i =0;i<s.size();i++){
    cout<<move(s[i],N);
  }
  return 0;
}