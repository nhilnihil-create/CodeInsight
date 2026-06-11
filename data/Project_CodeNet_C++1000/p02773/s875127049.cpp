#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i = 0;i < n;i++){
    cin >> s[i];
  }
  sort(s.begin(), s.end());
  int c=1;
  int z=1;
  for(int i=1;i<n;i++){
    if (s[i-1]==s[i]){
      z++;
      c=max(c,z);
    }
    else{
      z=1;
    }
  }
  z=1;
  if(n==1){
    cout<<s[0]<<endl;
  }
  else if(c==1){
    for(int i=0;i<n;i++){
    cout<<s[i]<<endl;
    }
  }
  else{
    for(int i=1;i<n;i++){
      if(s[i-1]==s[i]){
        z++;
      }
      else{
        z=1;
      }
      if(c==z){
        cout<<s[i-1]<<endl;
      }
    }
  }
}