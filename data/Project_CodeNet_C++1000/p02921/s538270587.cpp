#include<iostream>
using namespace std;
int main(){
  int i,ans=0;
string s,t;
  cin >> s >> t;
  for(i=0;i<s.size();i++){
  if(s.at(i)==t.at(i)){
  ans++;
  }
  }
  cout << ans << endl;
}