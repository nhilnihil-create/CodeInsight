#include <iostream>
#include <cmath>

using namespace std;

bool sosu(int n){
	if(n == 1) return true;
	if(n == 1) return true;
	if(n%2 == 0) return false;
	for(int i=3;i<=sqrt(n);i+=2){
		if(n % i == 0) return false;
	}
	
	return true;
}

int main(){
	int n;
	while(cin >> n, n){
		int count = 0;
		for(int i=(n%2==0?n+1:n+2);i<=2*n;i+=2){
			if(sosu(i)) count++;
		}
		if(n == 1) count = 1;
		cout << count << endl;
	}

	return 0;
}