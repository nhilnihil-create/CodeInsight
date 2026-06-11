#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  map<string,int>	s;
  for(int i=0;i<n;i++){
    string str;	cin >> str;
    if(s.count(str))	s[str]+=1;
    else	s[str]=1;
  }
  
  int m=0;
  for(auto x:s){
    m=max(m,x.second);
  }
  
  for(auto x:s){
    if(x.second==m)	cout << x.first << endl;
  }
  
}