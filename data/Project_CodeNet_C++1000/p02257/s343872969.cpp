#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n, pcount, a, d;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		d = 0;
		cin >> a;
		if(a == 3){
			pcount++;
			continue;
		}
		for(int j = 2; j <= sqrt(a); j++){
			if(a%j == 0){
				d = 1;
				break;
			}
		}
		if(d == 0)
			pcount++;
	}
	
	cout << pcount << endl;
	
	return 0;
}