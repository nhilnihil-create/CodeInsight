#include<iostream>
using namespace std;

main(){
	int a,b;
	do{
		cin >>a >>b;
		if(a<=b && b!=0){
			cout << a << " " << b << "\n";
		}
		else if(b<a){
			cout << b << " " << a << "\n";
		}		
	}while(a!=0||b!=0);
}