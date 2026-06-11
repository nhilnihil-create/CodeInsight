#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long res = 0;
	int former = -1;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (i == 0) {
			former = a;
		}
		else {
			if (former > a) {
				res += former - a;
			}
			else if (a > former) {
				former = a;
			}
		}


	}
	cout << res << endl;
	return 0;
}