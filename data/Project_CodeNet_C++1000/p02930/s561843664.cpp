#include<bits/stdc++.h>
using namespace std;
int f(int x,int y,int n){
if(x<=n/2 && n/2+1<=y)
  return 1;
  else if(x<=n/2 &&y<=n/2)
    return f(x,y,n/2)+1;
  else
    return f(x-n/2,y-n/2,n-n/2)+1;
}
int main(){
  int N;cin>>N;
  for(int i=1;i<N;i++){
  for(int j=i+1;j<N;j++)
    cout<<f(i,j,N)<<" ";
    cout<<f(i,N,N)<<endl;
   }
  return 0;
}