#include<iostream>
using namespace std;
int main(){
string s,t;
  int ans=0;
  cin >> s >> t;
  if(s.at(0)==t.at(0)){
  ans++;
  }
  if(s.at(1)==t.at(1)){
  ans++;
  }
  if(s.at(2)==t.at(2)){
  ans++;
  }
  cout << ans << endl;
}