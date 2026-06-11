#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e7 + 10;
bool prime[nmax];

int main(){
	int n;
	cin >> n;
	vector<long long>divisors(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; j += i)
			++divisors[j]; 
	unsigned long long suma = 0;
	for(int i = 1; i <= n; i++){
		suma = suma + (long long)(i * divisors[i]);
	}
	cout << suma << endl;
}

