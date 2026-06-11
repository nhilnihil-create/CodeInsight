#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>

using namespace std;
int main() {
	int N, M;
	cin >> N >> M;

	int ans = 0;

	while (N >= 2) {
		N--;
		ans += N;
	}

	while (M >= 2) {
		M--;
		ans += M;
	}

	cout << ans << endl; 

}