#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;cin>>a>>b;
  vector<int> c(210,0);
  c[1]=300000,c[2]=200000,c[3]=100000;
  cout<<(a==1&&b==1?1000000:c[a]+c[b]);
}