#include<iostream>
using namespace std;

int main(){
	int a, b, c, o;
	cin >> a >> b >> c;
	if(b < a){
		o = a;
		a = b;
		b = o;
	}
	if(c < b){
		o = b;
		b = c;
		c = o;
	}
	if(b < a){
		o = a;
		a = b;
		b = o;
	}
	cout << a << " " << b << " " << c << endl;
}