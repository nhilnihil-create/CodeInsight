#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<set>
#include<string>
#include<bitset>
#include<queue>
using namespace std;


int main() {
	int N;
	cin >> N;
	long long pickup_sum = 0;
	vector<int> cnt(N, 0);
	int A[200050];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		pickup_sum += cnt[A[i]];
		cnt[A[i]]++;
	}
	for (int i = 0; i < N; i++) {
		long long ans = pickup_sum - cnt[A[i]] + 1;
		cout << ans << endl;
	}
	
	return 0;
}