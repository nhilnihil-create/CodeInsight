#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, K; cin >> N >> K;
	vector<long long int>score(N);
	for (int i = 0; i < N; i++)cin >> score[i];
	for (int i = K; i < N; i++) {
		if (score[i] > score[i - K]) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}