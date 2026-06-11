#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[5001];
int sum[5001];
main(){
  while(1){
    int res=-1000000;
    scanf("%d",&n);
    if(n==0) break;
    int sm=0;
    for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
      sm+=a[i];
      sum[i]=sm;
    }
    for(int i=0;i<n;i++){
      for(int j=i;j<n;j++){
	int s=i-1<0?0:sum[i-1];
	res=max(res,sum[j]-s);
      }
    }
    printf("%d\n",res);
  }
}