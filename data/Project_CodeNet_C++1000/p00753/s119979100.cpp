#include<iostream>
using namespace std;
#define N 246912
int main(){
  int n,a[246912];
  for(int i=0;i<N;i++)a[i]=i+1;
  for(int i=0;i<N;i++)a[i]=true;
  a[0]=a[1]=false;
  for(int i=0;i<N;i++)
    if(a[i]==true)
      for(int j=i*2;j<N;j+=i)
	  a[j]=false;

  while(1){
    int count=0,n;
    cin>>n;
    if(n==0)break;
    for(int i=n+1;i<=2*n;i++)
      if(a[i]==true)count++;    
    cout<<count<<endl;
  }
  return 0;
}