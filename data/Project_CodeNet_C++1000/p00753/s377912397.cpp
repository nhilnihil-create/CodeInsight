#include<bits/stdc++.h>
using namespace std;
int p[300000];
int main(){
  p[0]=p[1]=1;
  for(int i=2;i*i<300000;++i){
    if(!p[i]){
      for(int j=i+i;j<300000;j+=i) p[j]=1;
    }
  }
  int n;
  while(cin>>n,n){
    int cnt=0;
    for(int i=n+1;i<=2*n;++i)
      if(!p[i]) cnt++;
    cout<<cnt<<endl;
  }
  return 0;
}