#include <bits/stdc++.h>
using namespace std;

char itoc(int num){
	if(num == 0){
		return '0';
	}else if(num == 1){
		return '1';
	}else if(num == 2){
		return '2';
	}else if(num == 3){
		return '3';
	}else if(num == 4){
		return '4';
	}else if(num == 5){
		return '5';
	}else if(num == 6){
		return '6';
	}else if(num == 7){
		return '7';
	}else if(num == 8){
		return '8';
	}else{
		return '9';
	}
}

int main() {
	int a, b;
	cin >> a >> b;

	string ab,ba;
	for(int i=0;i<b;i++){
		ab.push_back(itoc(a));
	}
	for(int i=0;i<a;i++){
		ba.push_back(itoc(b));
	}
	if(ab <= ba){
		cout << ab << endl;
	}else{
		cout << ba << endl;
	}
}
