#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N; 
	double dans;
	if (1== N%2) {
		dans = ((N + 1) / 2) / (double)N;
	}
	else{
		dans = 1 / 2.0;
	}

	printf("%.10f\n", dans);
	return 0;
}