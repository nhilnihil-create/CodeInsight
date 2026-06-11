#include <bits/stdc++.h>
using namespace std;


int main() {
	float x;
	cin >> x;
	if(floor(ceil(x / 1.08) * 1.08)  == x){
		cout << ceil(x / 1.08) << endl;
	} else {
		cout << ":(" << endl;
	}	
 }
