#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  bool t=true;
  for(int i=0;i<s.size();i++){
   if(s[i]=='7'){
     t=false;
     cout << "Yes" << endl;
     break;
   }
  }
  if(t)cout << "No" << endl;
}
