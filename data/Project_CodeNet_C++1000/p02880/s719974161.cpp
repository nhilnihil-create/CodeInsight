#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin>>n;
  bool can=false;
  for(int i=1;i<=9;i++) {
    for(int j=1;j<=9;j++) {
      if(i*j==n) can=true;
    }
  }
  if(can) cout<<"Yes\n";
  else cout<<"No\n";
}
