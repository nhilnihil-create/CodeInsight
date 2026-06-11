#include <iostream>
#include <string>
using namespace std;
int main(){
	string a;
	cin >> a;
	char x=a[0];
	char y=a[1];
	char z=a[2];
	if (x=='R' && y=='R' && z=='R'){
		cout << 3;
	}
	else if (x=='R' && y=='R' && z!='R'){
		cout << 2;
	}
	else if (x!='R' && y=='R' && z=='R'){
		cout << 2;
		
	}
	else if (x!='R' && y!='R' && z!='R'){
		cout << 0;
	}
	else{
		cout << 1;
	}
	return 0;
}