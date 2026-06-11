#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;	cin >> s;
  int q;	cin >> q;
  
  string left="";
  string right="";
  
  int dir=1;
  for(int i=0;i<q;i++){
    int t;	cin >> t;
    if(t==1){
      dir*=(-1);
    }else if(t==2){
      int t;	cin >> t;
      char c;	cin >> c;
      if(t==1){
        if(dir>0)	left=c+left;
        if(dir<0)	right=right+c;
      }else if(t==2){
        if(dir>0)	right=right+c;
        if(dir<0)	left=c+left;
      }
    }
  }
  s=left+s+right;
  if(dir==-1)	reverse(s.begin(),s.end());
  cout << s;
}