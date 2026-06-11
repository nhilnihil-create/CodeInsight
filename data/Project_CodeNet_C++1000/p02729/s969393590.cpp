#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m; cin>>n>>m;
  int s,o_e;
  s=((n+m)*(n+m-1))/2;
  o_e=n*m;
  cout<<s-o_e<<endl;
}