#include <bits/stdc++.h>
using namespace std;

int main(){
	int m1, d1;
	cin >> m1 >> d1;
	int m2, d2;
	cin >> m2 >> d2;
	if(m2 - m1 > 0 && d2 - d1 < 0){
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
}
