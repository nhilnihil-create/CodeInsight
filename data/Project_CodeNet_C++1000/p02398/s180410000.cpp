#include<iostream>
using namespace std;

main(){
	int a,b,c,i,l=0;
	cin >>a>>b>>c;
	for(i=a;i<=b;i++){
		if(c%i==0){
			l++;
		}
	}
	cout << l<<"\n";
}