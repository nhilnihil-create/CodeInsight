#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n; cin >> n;
	long long a = 1, b;
	for (long long i = 2; i * i <= n; i++){
		if(n % i == 0) a = i;
	}
	b = n / a;
	cout << a + b - 2 << endl;
	return 0;
}
