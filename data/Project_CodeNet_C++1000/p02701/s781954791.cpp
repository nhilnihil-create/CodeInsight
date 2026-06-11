#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,i,kotae=1;
  cin>>n;
  string s[n];
  for(i=0;i<n;i++){
    cin>>s[i];
  }
  sort(s,s+n);
  for(i=1;i<n;i++){
    if(s[i]!=s[i-1]){
      kotae++;
    }
  }
  cout<<kotae;
}
