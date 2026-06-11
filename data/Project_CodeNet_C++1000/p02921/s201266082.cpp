#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,s1;
  cin>>s>>s1;
  int count=0;
  for(int i=0;i<3;i++){
    if(s[i]==s1[i])
      	count++;
  }
  cout<<count;
  return 0;
}