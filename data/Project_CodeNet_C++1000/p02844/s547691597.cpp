#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,ans=0;
  cin >> n;
  string s;
  cin >> s;
  
  for(int i=0;i<1000;i++){
    int x=i;
    string key="";
    for(int j=0;j<3;j++){
      key+='0'+x%10;
      x/=10;
    }
    
    int point=0;
    for(int j=0;j<n;j++){
      if(s.at(j)==key.at(point)){
        point++;
      }
      if(point==3){
        break;
      }
    }
    if(point==3){
      ans++;
    }
  }
  cout << ans;
}