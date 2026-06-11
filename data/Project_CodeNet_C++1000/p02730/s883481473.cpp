#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n=s.length();
  int l=(n-1)/2,r=(n+3)/2;
  bool judge=true;
  for(int i=0;i<n/2;i++){
    if(s[i]!=s[n-i-1]){
      judge=false;
      break;
    }
  }
  for(int i=0;i<l/2;i++){
    if(s[i]!=s[l-i-1]){
      judge=false;
      break;
    }
  }
  for(int i=r;i<n;i++){
    if(s[i]!=s[n-i-1]){
      judge=false;
      break;
    }
  }
  if(judge){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}