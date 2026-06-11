#include <iostream>

using namespace std;

const int MAX = 246913;

int main()
{
	int n;
	bool prime[MAX];
	prime[2] = true;
	for(int i=3; i < MAX; i+=2) prime[i] = true;
	for(int i=3; i < MAX; i+=2) {
		if(prime[i]) {
			for(int j=i+i+i; j < MAX; j+=i) {
				if(j&1) prime[j] = false;
			}
		}
	}
	while(cin >> n, n)
	{
		int cnt = 0;
		int m = (n << 1) + 1;
		if(n == 1) cnt++;
		n = (n&1)? n+2 : n+1;
		for(int i=n; i < m; i+=2) {
			if((i&1) && (prime[i])) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}