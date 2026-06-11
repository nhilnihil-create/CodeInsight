#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin>>n;
  string s; cin>>s;
  for(char& c:s){
    if(c+n>'Z') c+='A'+n-'Z'-1;
    else c+=n;
  }
  cout<<s;
}