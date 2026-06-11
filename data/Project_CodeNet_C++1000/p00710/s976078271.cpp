#include<iostream>
using namespace std;
int main(){
  int n,r,p,c,a[51],b[51];
  while(cin>>n>>r){
    if(n==0 && r==0)break;
    for(int i=0;i<n;i++)
      a[i]=n-i;
    for(int i=0;i<r;i++){
      cin>>p>>c;
      for(int i=0;i<n;i++)
	b[i]=a[i];
      for(int i=0;i<c;i++)
	a[i]=b[p-1+i];
      for(int i=0;i<p-1;i++)
	a[c+i]=b[i];
    }
    cout<<a[0]<<endl;
  }
  return 0;
}