#include <iostream>
using namespace std;

bool prime[300000];

void is_prime(int n){
	for(int i = 0; i <= n * 2; ++i)
		prime[i] = true;
	
	prime[0] = prime[1] = false;
	
	for(int i = 2; i <= n * 2; ++i){
		if(prime[i]){
			for(int j = i * 2; j <= n * 2; j += i)
				prime[j] = false;
		}
	}
}
int main() {
	int n;
	while(cin >> n && n){
		is_prime(n);
		int ans = 0;
		for(int i = n + 1; i <= n * 2; ++i){
			if(prime[i])
				ans++;
		}
		
		cout << ans << endl;
	}
	return 0;
}