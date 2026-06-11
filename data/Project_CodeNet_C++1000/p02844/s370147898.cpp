#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,c=0; cin>>n;
  string s; cin>>s;
  int a[1000]={0};
  for(int i=0;i<1000;i++){
    string ts=s,ss="00";
    ss+=to_string(i);
    ss=ss.substr(ss.size()-3);
    bool f=true;
    for(char c:ss){
      if(ts.find(c)!=string::npos) ts=ts.substr(ts.find(c)+1);
      else{f=false; break;}
    }
    if(f) a[i]++;
  }
  for(int i:a) if(i) c++;
  cout<<c;
}