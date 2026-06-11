#include<bits/stdc++.h>
using namespace std;
void norm(string &s,vector<char> &c,int n){
  if(s.size()==n){
    cout<<s<<endl;
    return;
  }
  for(char x:c){
    s+=x;
    norm(s,c,n);
    s.pop_back();
  }
  c.push_back((char)c.size()+'a');
  s+=c.back();
  norm(s,c,n);
  c.pop_back();
  s.pop_back();
  return;
}
int main(){
  int n;
  cin>>n;
  string s;
  vector<char> c;
  norm(s,c,n);
}