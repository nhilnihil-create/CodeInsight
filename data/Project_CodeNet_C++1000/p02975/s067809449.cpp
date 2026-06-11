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
	long long N,x=0; cin >> N;
	vector<long long> a(N);
	for (int i = 0; i < N; i++) {
		long long a; cin >> a; x ^= a;
	}
	if (x)cout << "No" << endl;
	else cout << "Yes" << endl;
}



