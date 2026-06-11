//JamesEw
#include <bits/stdc++.h>
using namespace std;

int a, b, d;
bool c=false;

int main (){
	cin >> d;
	for (int a=1;a<=9;a++){ 
		for (int b=1;b<=9;b++){
		if (d==a*b){
			c=true;
		}
		}
		}
		if (c==false){
			cout << "No" << endl;
		}else if (c==true){
			cout << "Yes" << endl;
		}
}
		