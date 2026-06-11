#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int count=0;
  for(int i=0;i<s.size();i++){
    if(i%2==0){
      if(s.at(i)=='L') count++;
    }
    else{
      if(s.at(i)=='R') count++;
    }
  }
  if(count==0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}