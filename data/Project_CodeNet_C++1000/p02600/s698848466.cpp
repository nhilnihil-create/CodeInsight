/***************************
 * Author  : dhakad_123  ***
 * Created : 26.07.2020  ***
 **************************/

#include<bits/stdc++.h>
using namespace std;


int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int x; 
	cin >> x;

	
	if(x >= 400 && x <= 599){
		cout << 8 << endl;
	}

	else if(x >= 600 && x <= 799){
		cout << 7 << endl;
	}

	else if(x >= 800 && x <= 999){
		cout << 6 << endl;
	}
	else if(x >= 1000 && x <= 1199){
		cout << 5 << endl;
	}

	else if(x >= 1200 && x <= 1399){
		cout << 4 << endl;
	}

	else if(x >= 1400 && x <= 1599){
		cout << 3 << endl;
	}
	else if(x >= 1600 && x <= 1799){
		cout << 2 << endl;
	}
	else {
		cout << 1 << endl;
	}


	return 0;
}
