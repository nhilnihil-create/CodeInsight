#include <iostream>
using namespace std;

int p[246913];
bool is_prime[246913];
int prime(int n){
	int sum = 0;
	for(int i=0;i<=2*n;i++){
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;
	for(int i=2;i<=2*n;i++){
		if(is_prime[i] == true){
			p[sum++] = i;
		}
		for(int j=i+i;j<=2*n;j+=i){
			is_prime[j] = false;
		}
	}
	return sum;
}

int main()
{
	int n;
	while(cin >> n){
		if(n==0)
			break;
		int ans = 0;
		int a = prime(n);
		for(int i=0;i<a;i++){
			if(p[i] > n && p[i] <= 2*n)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
	