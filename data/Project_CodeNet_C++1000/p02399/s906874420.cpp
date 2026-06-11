#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int a,b,d,r;
	double f;

	cin>>a>>b;
	if(a==0||b==0){
		cout<<"0 0 0"<<endl;
		return 0;
	} 
	d=a/b;
	r=a%b;
	f=(double)a/(double)b;
	cout<<d<<" "<<r<<" "<<fixed<<setprecision(5)<<f<<endl;
	return 0;
}