#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,x,l,d=0,c=1,i;
  cin>>n>>x;
  for(i=0;i<n;i++){
    cin>>l;
    d+=l;
    if(d>x) break;
    c++;
  }
  cout<<c<<endl;
}