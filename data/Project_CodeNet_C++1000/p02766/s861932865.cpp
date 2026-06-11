#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n,k;
  cin>>n>>k;
  
  int cnt=0;
  
  while(k<=n){
    n/=k;
    cnt++;
  }
  cout<<cnt+1<<endl;
  return 0;
}