#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int i;
  int ans = s.length();
  bool tmp = true;
  for(i=1;i<s.length();i++){
    if(s[i]==s[i-1]){
      ans--;
      i+=2;
    }
  }
  cout<<ans<<endl;
}
