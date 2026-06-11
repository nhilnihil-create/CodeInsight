#include<iostream>
using namespace std;

void hoge(){
	int i,j;
	for(i=1;i<=9;i++){
	 for(j=1;j<=9;j++){
	  cout<<i<<"x"<<j<<"="<<i*j<<endl;
	 }
	}
}

int main(){
	
	hoge();
	
	return 0;
}