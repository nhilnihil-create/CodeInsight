#include <bits/stdc++.h>
using namespace std;
int s[55];
int main(){
  int a,m=0;
  cin>>a;
  for(int i=0;i<a;i++){
    cin>>s[i];
    for(int j=0;j<i;j++)
      m+=s[j]*s[i];
    for(int j=i+1;j<a;j++)
      m+=s[j]*s[i];
  }
  cout<<m;
  return 0;
}