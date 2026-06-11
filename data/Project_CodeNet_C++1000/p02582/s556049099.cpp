#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans = 0;
  if(s == "RSR"){
    cout<<1<<endl;
    return 0;
  }
  for(int i=0;i<3;i++){
    if(s[i] == 'R')ans++;
  }
  
  cout << ans << endl;
  return 0;
}