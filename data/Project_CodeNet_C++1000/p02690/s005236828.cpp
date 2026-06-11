#include<iostream>
using namespace std;


long long int power(long long int x, int y){
	long long int ans = 1;
	while(y--) ans *= x;
	return ans;
}


int main(){
	long long int x;


	cin >> x;

	for(long long int a=-1000; a <= 1000; a++){
		for(long long int b=-1000; b <= 1000; b++){
			if(power(a, 5) - power(b, 5) == x){
				cout << a << " " << b << endl;
				return 0;
			}
		}
	}
}
