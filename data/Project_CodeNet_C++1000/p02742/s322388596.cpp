#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	
	 long long int N, M;
	cin >> N >> M;
	if (N == 1 || M == 1)cout << 1 << endl;
	else if (N * M % 2 == 1)cout << N * M / 2 + 1 << endl;
	else cout << N * M / 2 << endl;
	return 0;
}
