#include <bits/stdc++.h>
using namespace std;

int main(void){
	int x,y;
	cin >> x >> y;
	
	while(true){
		if(x < y)swap(x,y);
		if(y == 0)break;
		x %= y;
	}

	cout << x << endl;
	return 0;
}