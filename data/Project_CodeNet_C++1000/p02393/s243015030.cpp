#include<iostream>

using namespace std;

main(){
	int a,b,c,k,count=1;
	
	cin>>a>>b>>c;
	while(count!=0){
	count=0;
		if(c<b){
		k=c;
		c=b;
		b=k;
		count++;
	}
	if(a>b){
		k=a;;
		a=b;
		b=k;
		count++;
	}
	}
	cout<<""<<a<<" "<<b<<" "<<c<<endl;
}	