#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  bool t=true;
  cin >> s;
  for(int i=0;i<s.size();i++){
    if(i%2==0 && s[i]=='h' && s[i+1]=='i')continue;
    else if(i%2==1)continue;
    else{
      t=false;
      cout << "No" << endl;
      break;
    }
  }
  if(t)cout << "Yes" << endl;
}