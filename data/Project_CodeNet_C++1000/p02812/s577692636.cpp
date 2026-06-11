#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,count=0;
  string s;
  cin>>n;
  cin>>s;
  for(int i=0;i<n;i++){
    if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
      count++;
    }
  }
  cout<<count<<endl;
} 