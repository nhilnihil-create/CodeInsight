#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<string> s(n);
  vector<int> a(n);
  string x;
  for(int i=0;i<n;++i)cin>>s[i]>>a[i];
  cin>>x;
  bool f=false;
  int c=0;
  for(int i=0;i<n;++i){
    if(f)c+=a[i];
    if(x==s[i])f=true;
  }
  cout<<c;
}