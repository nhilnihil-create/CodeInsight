#include<iostream>
using namespace std;

main(){
	int x,y,k;
	
	while(1){
		cin>>x>>y;
		if(x==0 && y==0) break;
		if(x>y){
			k=x;
			x=y;
			y=k;
		}
		cout<<""<<x<<" "<<y<<endl;
	}
}