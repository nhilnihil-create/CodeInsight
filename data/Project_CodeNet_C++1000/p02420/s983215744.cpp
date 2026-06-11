#include<iostream>
using namespace std;

int main(){
  int m, h;
  string s, t, u;

  while(1){
    cin>>s;
    if(s[0]=='-') break;
    cin>>m;
    for(int i=0;i<m;i++){
      cin>>h;
      u=s.substr(0, h);
      t=s.substr(h, s.length());
      s=t+u;
    }
    cout<<s<<endl;
  }

  return 0;
}