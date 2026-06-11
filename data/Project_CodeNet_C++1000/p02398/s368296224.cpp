#include<iostream>
using namespace std;

main(){
	int a,b,c,count=0;
	cin>>a>>b>>c;
	
	for(int i=a;;i++){
	if(i==b+1) break;
	if(c%i==0) count++;
}
	cout<<""<<count<<endl;
}