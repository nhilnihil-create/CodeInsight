#include<iostream>
using namespace std;

main(){
	int hour,min,sec;
	cin>>sec;
	
	hour=sec/3600;
	min=(sec/60)-60*hour;
	sec=sec-3600*hour-60*min;
	
	cout<<""<<hour<<":"<<min<<":"<<sec<<endl;
}