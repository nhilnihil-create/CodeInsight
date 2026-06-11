#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  string s;
  cin >> s;
  bool chk = false;
  if(c<d)chk = true;
  else{
    for(int i=b-1;i<=d-1;i++){
      if(s[i]=='.' && s[i-1]=='.' && s[i+1]=='.')chk = true;
    }
  }
  for(int i=a-1;i<c-1;i++){
    if(s[i] == '#' && s[i+1]=='#')chk = false;
  }
  for(int i=b-1;i<d-1;i++){
    if(s[i] == '#' && s[i+1]=='#')chk = false;
  }
  if(chk)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
