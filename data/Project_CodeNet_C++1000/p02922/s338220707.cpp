#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 1e6;
int a, b; 

int main() {
	cin >> a >> b;
	a--, b--;
	int ans = b / a + (b % a != 0);
	cout << ans << endl;
	return 0;
} 