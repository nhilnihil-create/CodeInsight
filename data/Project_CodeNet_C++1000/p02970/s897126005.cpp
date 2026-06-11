#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
using namespace std;

//ABC134 B
int main() {
	int N, D;
	cin >> N >> D;

	int cover = 2 * D + 1;
	int ans = 1;
	while (cover < N) {
		cover += 2 * D + 1;
		ans++;
	}
	cout << ans << endl;
}