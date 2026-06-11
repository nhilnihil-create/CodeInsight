#include<bits/stdc++.h>
using namespace std;
int main(){
  int x;
  cin>>x;
  bool tf=false;
  while(1){
  	for(int i=2;i<pow(x,0.5);i++){
  		if(x%i==0){
      		tf=true;
      		break;
    	}
  	}
  	if(tf==true){
    	x++;
      	tf=false;
  	}else{
    	cout<<x<<endl;
    	return 0;
  	}
  }
}