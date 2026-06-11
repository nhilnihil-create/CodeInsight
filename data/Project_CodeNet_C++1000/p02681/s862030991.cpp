#include<bits/stdc++.h>
using namespace std;

int main(){
  string s, t;
  cin>>s>>t;
  int a=s.size();
  for(int i=0;i<a;i++){
    if(s.at(i)!=t.at(i)){
      cout<<"No"<<endl;
  return 0;}}
  if(t.size()-a==1)
    cout<<"Yes"<<endl;
}