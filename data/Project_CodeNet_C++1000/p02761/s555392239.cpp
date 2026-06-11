#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin>>n>>m;
  int s[10],c[10];
  for(int i=0;i<m;i++) cin>>s[i]>>c[i];
  
  for(int i=0;i<=999;i++) {
    bool flag=true;
    string num=to_string(i);

    if(n!=num.size()) continue;

    for(int i=0;i<m;i++) {
      if(num[s[i]-1]-'0'!=c[i]) flag=false;
    }

    if(flag) {
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}
