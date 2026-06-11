#include<iostream>
using namespace std;

int main(){
	int a, b, c, d, e, f, g, h;
	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	int suma = a+b+c+d, sumb = e+f+g+h;

	if(suma >= sumb){
		cout << suma << endl;
	}else{
		cout << sumb << endl;
	}

	return 0;
}