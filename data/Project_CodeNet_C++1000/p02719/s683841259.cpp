#include <bits/stdc++.h>
using namespace std;


int main() {
	int64_t N, K,F,T;
	cin >> N >> K;
	
	F = N % K;
	T = abs(K - F);
	if (F<T)
	{
		cout << F << endl;
	}
	else {
		cout << T << endl;
	}
	
}
