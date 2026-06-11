#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,d;
  cin>>n>>d;
  int ans=0;
  while(n>0){
      int tobesubtracted=2*d+1;
      n-=tobesubtracted;
      ans++;
  }
  cout<<ans<<endl;
}