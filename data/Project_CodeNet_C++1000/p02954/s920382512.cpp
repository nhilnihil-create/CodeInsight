#include<bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n,i,r,l;
  cin>>s;
  n=s.length();
  vector<int> a(n);
  i=0;
  while(i<n){
    r=i;
    i++;
    while(s.at(i)=='R') i++;
    l=i;
    a.at(l-1)+=(l-r+1)/2;
    a.at(l)+=(l-r)/2;
    i++;
    while(i<n && s.at(i)=='L') i++;
    r=i;
    a.at(l-1)+=(r-l)/2;
    a.at(l)+=(r-l+1)/2;
  }
  for(i=0;i<n;i++){
    cout<<a.at(i);
    if(i<n-1) cout<<' ';
    else cout<<endl;
  }
}