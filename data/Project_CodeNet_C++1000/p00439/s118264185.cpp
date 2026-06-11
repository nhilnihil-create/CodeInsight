#include<iostream>
using namespace std;
main(){
  int n,k,a;
  int node1=0,node2,max;
  int ruiseki[100001]={0};
  while(1){
    cin>>n>>k;
    if(n==0&&k==0)break;
    node2=k;
    for(int i=1;i<=n;i++){
      cin>>a;
      ruiseki[i]=ruiseki[i-1]+a;
      if(i>=k){
	if(i==k){
	  max=ruiseki[node2]-ruiseki[node1];
	}
	else if(max<ruiseki[node2]-ruiseki[node1]){
	  max=ruiseki[node2]-ruiseki[node1];
	}
	node1++;
	node2++;
      }
    }
    cout<<max<<endl;
    node1=0;
  }
}