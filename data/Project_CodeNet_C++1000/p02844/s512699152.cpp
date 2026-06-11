#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,c,ans=0;
  string s,x;
  map<string,int>a;
  cin >> n >> s;
  for(int i=0;i<1000;i++){
    x=to_string(i);
    while(x.size()!=3) x='0'+x;
    c=0;
    for(int j=0;j<n;j++){
      if(s.at(j)==x.at(c)) c++;
      if(c==3) break;
    }
    if(c==3) ans++;
  }
  cout << ans << endl;
  return 0;
}