#include<iostream>
using namespace std;
int a,n,i,j,k;
bool b[40001]={1};
main(){
  for(cin>>n;i++<n;){
    cin>>a;
    for(k=40001;k+1;--k)b[k]?b[k+a]=1:0;
  }
  for(cin>>n;j++<n;cout<<(b[i]?"yes\n":"no\n"))cin>>i;
}