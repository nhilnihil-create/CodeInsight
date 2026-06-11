#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin>>n>>s;
  int ans=0;
  for(int i=0;i<1000;i++) {
    bool i0=false,i1=false,i2=false;
    string I="";
    if(i<100) I+='0';
    if(i<10) I+='0';
    I+=to_string(i);
    for(int j=0;j<n;j++) {
      if(s[j]==I[2]&&i0&&i1) i2=true;
      if(s[j]==I[1]&&i0) i1=true;
      if(s[j]==I[0]) i0=true;
    }
    if(i0&&i1&&i2) ans++;
  }
  cout<<ans<<endl;
}
