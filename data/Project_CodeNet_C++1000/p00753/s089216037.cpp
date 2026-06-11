#include <iostream>
#include <cmath>
using namespace std;


bool isPrime(int n){
	if(n == 2) return true;
	for(int i = 2;i <= sqrt(n);i++)
		if(!(n%i)) return false;
	return true;
}


int main(){
	int n;
	int ans;
	while(ans = 0, cin >> n, n){
		for(int i = n+1;i <= 2*n;i++){
			if(isPrime(i)) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}