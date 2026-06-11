#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	long long N, K,x=0,mod=1000000007; cin >> N >> K;
	vector<long long> A(N);
	for (int i = 0; i < N; i++)cin >> A[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i] > A[j]&&i<j) {
				x += (K * (K + 1)) / 2;
				x %= mod;
			}
			if (A[i]>A[j] && i>j) {
				x += (K * (K - 1)) / 2;
				x %= mod;
			}
		}
	}
	cout << x << endl;
	
}



