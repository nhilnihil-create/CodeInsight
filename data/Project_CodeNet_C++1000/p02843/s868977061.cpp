#include<bits/stdc++.h>
using namespace std;
int main(){
  int X;
  cin>>X;
  int q=X%100,p=X/100,count=0;
  for(int i=5;i>0;i--){
    while(q>=i){
      q-=i;
      count++;
    }
  }
  if(count<=p)
    cout<<1;
  else
    cout<<0;
}