#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin>>s;
  for(int i=1;i<s.size();i+=2){
    cin>>s.at(i);
    if(s.at(i)=='R'){
      cout<<"No";
      return 0;
    }
  }
  for(int i=0;i<s.size();i+=2){
   if(s.at(i)=='L'){
     cout<<"No";
     return 0;
   }
  }
  cout<<"Yes";
}