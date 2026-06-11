#include<bits/stdc++.h>
using namespace std;
int main(){
  while(1){
    int x;
    cin>>x;
    int co=0,a=0;
    if(x==0) break;
    for(int i=x+1;i<=2*x;i++){
      a=0;
      for(int j=2;j<=sqrt(i)+1;j++){
	if(i==1) {
	  a=1;
	  break;
	}
	
	if(i==2){
	  break;
	}
	if(i%j==0){
	  a=1;
	  break;
	}
      }
      if(a==0) co++;
    }
    cout<<co<<endl;
  }
  return 0;
}

