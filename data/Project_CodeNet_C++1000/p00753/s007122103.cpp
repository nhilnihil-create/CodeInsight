#include <iostream>
using namespace std;

const int max_n = 123456*2;
bool is_prime[max_n+1];

int sieve(int n)
{
	int p = 0;
	for(int i=0;i<=2*n;i++){
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;
	for(int i=2;i<=2*n;i++){
		if(is_prime[i]){
			if(n<i && i <= 2*n)
				p++;
			for(int j=2*i;j<=2*n;j+=i)
				is_prime[j] = false;
		}
	}
	return p;
}

int main()
{
	int n;
	while(cin >> n){
		if(!n)
			break;
		cout << sieve(n) << endl;
	}
	return 0;
}