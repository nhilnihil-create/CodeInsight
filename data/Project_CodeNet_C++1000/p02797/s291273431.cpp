#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	int N;
	int K;
	int S;
	cin >> N >> K >> S;

	vector<int> v(N - K + 1, 0);

	if (S >= (N - K + 1)) {
		for (int i = 0; i < v.size() - 1; i++) {
			v[i] = 1;
			S--;
		}
		v[N - K] = S;
		for (int i = N - K + 1; i < N; i++) {
			v.push_back(v[i - N + K - 1]);
		}
	}
	else {
		for (int i = 0; i < v.size() - 1; i++) {
			v[i] = S + 1;
		}
		v[N - K] = S;
		for (int i = N - K + 1; i < N; i++) {
			v.push_back(S);
		}
	}
	
	

	for (int i = 0; i < N; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}