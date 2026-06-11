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
	vector<double> v(N);
	for (int i = 0; i < N; i++)cin >> v.at(i);
	for (int i = 0; i < N - 1; i++) {
		sort(v.begin(), v.end());
		v.push_back((v.at(0) + v.at(1)) / 2);
		v.erase(v.begin(),v.begin()+2);
	}
	cout << v.at(0) << endl;
	return 0;
}