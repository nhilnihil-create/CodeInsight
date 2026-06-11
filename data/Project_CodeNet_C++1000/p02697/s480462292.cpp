#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  if(n%2==1){
    for(int i=1;i<=m;i++)
      cout<<i<<' '<<m*2+1-i<<endl;
  }else{
    for(int i=1;i<=(m+1)/2;i++)
      cout<<i<<' '<<(m+1)/2*2+1-i<<endl;
    for(int i=1;i<=m/2;i++)
      cout<<i+(m+1)/2*2<<' '<<m/2*2+2-i+(m+1)/2*2<<endl;
  }
}