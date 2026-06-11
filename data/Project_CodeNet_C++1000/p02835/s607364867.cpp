#include <iostream>
using namespace std;

int a,b,c;
main(){
	cin>>a>>b>>c;
	if(a+b+c<22){
		printf("win");
	}
	else{
		printf("bust");
	}
}