#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int cnt=0;
  for(int i=0;i<s.size()/2;i++){
    if(s.at(i)!=s.at(s.size()-1-i)){
      cnt++;
    }
  }
  cout<<cnt;
}