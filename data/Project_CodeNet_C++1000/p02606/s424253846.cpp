#include <bits/stdc++.h>
using namespace std;

int main(){
	int L, R, d, c;
	cin >> L >> R >> d;
	c = R/d - L/d;
	
	if(L%d == 0)
		c++;
	
	cout << c << endl;
}