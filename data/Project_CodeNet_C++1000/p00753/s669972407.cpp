#include <iostream>

using namespace std;

const int MAX = 246913;
const int SIZE = 123457;

int main()
{
	int n;
	bool prime[SIZE];
	for(int i=0; i < SIZE; i++) prime[i] = true;
	for(int i=3; i < MAX; i+=2) {
		if(prime[((i-1)>>1)]) {
			for(int j=i+i+i; j < MAX; j+=i) {
				if(j&1) prime[((j-1)>>1)] = false;
			}
		}
	}
	while(cin >> n, n)
	{
		int cnt = 0;
		int m = (n << 1) + 1;
		for(int i=n+1; i < m; i++) {
			if((i&1) && (prime[((i-1)>>1)])) cnt++;
		}
		if(n == 1) cnt++;
		cout << cnt << endl;
	}
	return 0;
}