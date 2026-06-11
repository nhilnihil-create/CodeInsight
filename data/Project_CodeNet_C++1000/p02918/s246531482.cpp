#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k; cin>>n>>k;
  string s; cin>>s;
  
  int happy=0;
  int cnt=0;
  
  for (int i=0; i<n-1; i++){
    if (s[i]==s[i+1]) happy+=1;
    else cnt+=1;
  }
  
  cout<<min(n-1,happy+min(cnt,k)*2)<<endl;
}