#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


bool isPrime(int num){
	if (num < 2) return false;
	if (num == 2) return true;
	for (int i = 2; i <= (int)(sqrt(num) + 1); i++){
		if (num % i == 0) return false;
	}
	return true;
}
int main(){
	while(1){
		int n; cin >> n;
		if (n == 0) break;
		int ans = 0;
		for (int i = n + 1; i <= 2 * n; i++){
			if(isPrime(i)){
				ans++;
			}
		}
		cout << ans << endl;
	}
return 0;
}