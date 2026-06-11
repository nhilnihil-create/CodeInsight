#include<iostream>
using namespace std;
main(){
  int i,j,k,n,x,a,b,c=0;
  
  
  while(1){
    b=0;
    cin >> n >> x;
    if(n==0 && x==0)break;
    for(i=1;i<=n;i++){
      for(j=i+1;j<=n;j++){
	
	
	for(k=j+1;k<=n;k++){
      
	  a=0;
	  a=i+j+k;
	  if(a==x){
	    b+=1;
	  }

	}
      }
    }
    cout << b << endl;
  }
  
}