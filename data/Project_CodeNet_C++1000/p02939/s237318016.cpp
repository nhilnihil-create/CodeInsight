#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans=1;
  bool ok=false,ok2=false;
  for(int i=1;i<s.size();i++){
    if(ok){
      ans++;
      ok=false;
      ok2=true;
    }else if(ok2){
      ans++;
      ok=false;
      ok2=false;
    }else if(s.at(i)!=s.at(i-1)){
      ans++;
    }else{
      ok=true;
      ok2=false;
    }
  }
  cout << ans << endl;
  return 0;
}