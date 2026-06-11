#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<set>
#include<string>
#include<bitset>
using namespace std;


int main() {
	int N, M;
	cin >> N >> M;
	int a[150];
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int pick = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] * 4 * M >= sum) pick++;
	}
	if (pick >= M) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}