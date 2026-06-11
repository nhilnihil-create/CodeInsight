#include <bits/stdc++.h>
using namespace std;
bool mystery(string s){
string t=s;
  reverse(t.begin(),t.end());
  return s==t;
}
int main() {
  string s;
  cin>>s;
  int n=s.size();
  if(mystery(s)&& mystery(s.substr(0,(n-1)/2)) && mystery(s.substr(n+1/2)) ){
  cout<<"Yes"<<endl;
  }
  else{
  cout<<"No"<<endl;
  }
 
}