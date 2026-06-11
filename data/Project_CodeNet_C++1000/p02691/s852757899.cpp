#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<set>
#include<string>
#include<bitset>
#include<queue>
#include<map>
using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	map<int, int> mp; //連想配列
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		int R = i - A[i];
		int L = i + A[i];
		mp[L]++;
		ans += mp[R];
	}
	cout << ans << endl;
	return 0;
}