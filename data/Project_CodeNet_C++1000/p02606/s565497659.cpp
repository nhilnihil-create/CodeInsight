#include<bits/stdc++.h>
using namespace std;

int main(){
  int l,r,n;
  cin>>l>>r>>n;
  int cnt=0;
  for(int i=l;i<=r;i++){
    if(i%n==0) cnt++;
  }
  cout<<cnt;
  return 0;
}