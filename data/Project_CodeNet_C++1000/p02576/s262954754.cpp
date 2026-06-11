#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x,t;
  cin>>n>>x>>t;
  int m=(n/x+1)*t;
  if(n%x==0)m-=t;
  cout<<m;
}
