#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;	cin >> s;
  
  string t=s;
  reverse(t.begin(),t.end());
  if(s!=t){
    cout << "No";
    return 0;
  }
  
  t=s.substr(0,(s.size()-1)/2);
  string u=t;
  reverse(u.begin(),u.end());
  if(t!=u){
    cout << "No";
    return 0;
  }
  
  t=s.substr((s.size()+3)/2-1);
  u=t;
  reverse(u.begin(),u.end());
  if(t!=u){
    cout << "No";
    return 0;
  }
  cout << "Yes";
}