#include<cstdio>
#include<iostream>
using namespace std;
main(){
  long long n,i,j,t,a[5000],max;
  while(1){
    cin >> n;
    if(n==0){
      break;
    }
    else{
      for(i=0;i<n;i++){
	cin >> a[i];
      }
      max=a[0];
      for(i=0;i<n;i++){
	for(j=i,t=0;j<n;j++){
	  t=t+a[j];
	  if(t>max){
	    max=t;
	  }
	}
      }
      cout << max  << endl;
    }
  }
}