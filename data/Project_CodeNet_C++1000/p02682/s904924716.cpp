#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

using namespace std;

long long a, b, c, k;

int main(){
	cin >> a >> b >> c >> k;

	if(k < a || k == a){
		cout << k << endl;
	}
	else if(k < (a + b) || k == (a + b)){
		cout << a << endl;
	}
	else{
		cout << a - (k - (a + b)) << endl;
	}


	return 0;
}
