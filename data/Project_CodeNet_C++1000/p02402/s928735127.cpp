#include<iostream>
using namespace std;
int main(){
	int a,b;
	long long c=1000000,d=-1000000,e=0;
	cin >> a;
	for(;a>0;a--){
		cin >> b;
		if(b<c){
			c=b;
		}
		if(b>d){
			d=b;
		}
		e+=b;
	}
	cout << c << " " << d << " " << e << endl;
	return 0;
}