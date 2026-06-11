
#include<iostream>

using namespace std;
int main(void){

	int s1,s2,s3,s4,a;
	int t1,t2,t3,t4,b;

	cin >>s1;
	cin >>s2;
	cin >>s3;
	cin >>s4;
	a=s1+s2+s3+s4;
	cin >>t1;
	cin >>t2;
	cin >>t3;
	cin >>t4;
    b=t1+t2+t3+t4;
    if(a>b)cout << a << endl;
    else cout << b << endl;


	return 0;
}