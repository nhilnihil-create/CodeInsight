#include<bits/stdc++.h>
using namespace std;

int main(){
  string a;
  cin>>a;
  int c=0;
  for(auto b:a)c+=(int)(b-'0');
  if(c%9==0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
