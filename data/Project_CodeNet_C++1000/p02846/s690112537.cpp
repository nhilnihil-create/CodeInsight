#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	long long t1,t2,a1,a2,b1,b2;
	cin>>t1>>t2>>a1>>a2>>b1>>b2;
	long long d1=(b1-a1)*t1,d2=(b2-a2)*t2;
	if(d1+d2==0){
		cout<<"infinity";
		return 0;
	}
	if(d1<0){
		d1*=-1;
		d2*=-1;
	}
	if(d1+d2>0){
		cout<<0;return 0;
	}
	long long x=-(d1+d2);
	if(d1%x){
		cout<<2*(d1/x)+1 ;
	}
	else cout<<2*(d1/x);

}