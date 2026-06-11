#include<bits/stdc++.h>
using namespace std;
int m,n,q,A[20];
int a(int x,int y){
  if(x==0)return 0;
  if(y>=n)return 1;
 
  if(a(x,y+1)==0 || a(x-A[y],y+1)==0)return 0;
  else return 1;
}
 
int main(){ 
  cin>>n; 
  for(int i=0;i<n;i++)cin>>A[i];
  cin>>q;
  for(int i=0;i<q;i++){
    cin>>m;
    if(a(m,0)==0)
      cout<<"yes"<<endl;
    else 
      cout<<"no"<<endl;
  }
  return 0;
}