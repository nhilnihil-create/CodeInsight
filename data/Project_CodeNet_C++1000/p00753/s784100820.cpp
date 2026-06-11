#include<bits/stdc++.h>
#include<math.h>
using namespace std;

#define max 246913

int main(){
  int n;
  int count,limit;
  bool a[max];
  a[0]=a[1]=false;
  for(int i=2;i<max;i++) a[i]=true;
  limit=sqrt(max);
  /* cout<<limit<<endl;
     cout<<a[20]<<endl;*/
  for(int i=2;i<=limit;i++){
       if(a[i]==true){
           for(int k=2*i;k<max;k+=i){
	   a[k]=false;
           }
       }
   }
  /*cout<<a[20]<<endl;
    cout<<"ha?"<<endl;*/
  while(1){
    count=0;
    cin>>n;
    if(n==0) break;
    for(int i=n+1;i<2*n;i++){
      if(a[i]==true) count++;
    }
    if(n==1) cout<<"1"<<endl;
    else cout<<count<<endl;
  }
  return 0;
}

