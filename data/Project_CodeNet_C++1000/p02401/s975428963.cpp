#include "bits/stdc++.h"

using namespace std;

int main (){
	int a,c,k;
	string b;
	while(cin >> a >> b >> c){
		if(b == "?") break;
		if(b == "+") k = a + c;
		if(b == "-") k = a - c;
		if(b == "*") k = a * c;
		if(b == "/") k = a / c;
		cout << k << endl;
	}

return 0;
}