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

const long long mod = pow(10, 9) + 7;

int main() {
	long long N,ans=pow(10,18),x=0,y=0; cin >> N;
	vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i]; x += A[i];
	}
	for (int i = 0; i < N; i++) {
		ans = min(abs(x - y), ans);
		x -= A[i]; y += A[i];
	}
	cout << ans << endl;
}



