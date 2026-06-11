#include<bits/stdc++.h>
using namespace std;
int main(){
  while(1){
    int n,r;
    cin>>n>>r;
    if(n==0 && r==0) break;
    int a[51]={};
    for(int i=1;i<=n;i++){
      a[i]=n-i+1;
    }
    for(int i=0;i<r;i++){
      int p,c;
      cin>>p>>c;
      for(int j=1;j<=c;j++){
	for(int k=1;p+c-k>0;k++){
	  if(p+c-k>1)swap(a[p+c-k-1],a[p+c-k]);
	}
      }
    }
    cout<<a[1]<<endl;
  }
  return 0;
}

