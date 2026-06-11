#include<iostream>
using namespace std;

int main(){
	int a, b, c, info = 0;
	cin >> a >> b >> c;
	for (;;){
		if (c % a == 0){
			info += 1;
		}
		a += 1;
		if (a > b){
			break;
		}
	}

	cout << info << endl;
}
