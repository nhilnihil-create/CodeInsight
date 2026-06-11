#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin>>n>>s;
  int a=0;
  for(int i=1;i<n;i++){
    int t=1;
    for(int j=0;i+j<n;j++){
      if(s[j]==s[j+i])a=max(a,min(i,t++));
      else t=1;
    }
  }
  cout<<a;
}
