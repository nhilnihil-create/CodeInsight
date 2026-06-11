#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<vector<int>> data(N, vector<int>(2));
	for (int i = 0; i < N; i++)
		cin >> data[i][0];
	for (int i = 0; i < N; i++)
		cin >> data[i][1];
	long long max = data[0][1];
	for (int i = 0; i < N; i++) { //スタート地点のfor
		long long score = 0;
		int next = i;
		long long sum = 0;
		int return_count = 0;
		vector<int> return_checker(N, 0);
		int j = 0;
		while (1) {
			next = data[next][0] - 1;
			if (return_checker[next] == 1) {
				return_count = j ;
				break;
			}
			else 
				return_checker[next] = 1;
			sum += data[next][1];
			j++;
		}
		
		if (sum > 0)
			score = (K / return_count - 1) * sum;
		next = i;
		for (int j = 0; j < (K % return_count)+return_count; j++) {
			next = data[next][0] - 1;
			score += data[next][1];
			if (score > max)
				max = score;
		}
			

	}
	cout << max << endl;
	return 0;
}