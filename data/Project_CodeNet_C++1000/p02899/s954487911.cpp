#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	vector<int> b(N);
	for (int i = 0; i < N; i++)cin >> a.at(i);
	for (int i = 0; i < N; i++) {
		b.at(a.at(i)-1) = i+1;
	}
	for (int i = 0; i < N; i++) {
		if (i != N - 1) {
			cout << b.at(i) << " ";
		}
		else cout << b.at(N - 1) << endl;
	}
	
		return 0;
}
