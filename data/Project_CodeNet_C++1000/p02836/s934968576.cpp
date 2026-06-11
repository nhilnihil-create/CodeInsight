#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int a=s.size();
  int cnt=0;
  for(int i=0;i<a/2;i++){
    if(s[i]!=s[a-1-i])cnt++;
  }
  cout<<cnt<<endl;
}