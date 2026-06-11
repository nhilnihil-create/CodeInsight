#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<set>
#include<string>
#include<bitset>
using namespace std;

const int mod = 2019;

int main() {
	int N;
	cin >> N;
	vector<int> cnt(N);
	for (int i = 2; i <= N; i++) {
		int A;
		cin >> A;
		cnt[A - 1]++;
	}
	for (int i = 0; i < N; i++) {
		cout << cnt[i] << endl;
	}


	return 0;
}