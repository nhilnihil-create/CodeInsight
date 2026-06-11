#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int A[20];
int x[20][20], y[20][20];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		for (int j = 0; j < A[i]; j++) {
			cin >> x[i][j] >> y[i][j];
			x[i][j]--;
		}
	}
	int ans = 0;
	for (int bit = 0; bit < (1 << N); bit++) {
		int tmp = bit;
		vector<int> V;
		int info[20] = { 0 };
		for (int i = 0; i < N; i++) {
			info[i] = 0;
			if (tmp % 2 == 1) {
				V.push_back(i);
				info[i] = 1;
			}
			tmp /= 2;
		}
		bool out = false;
		for (int s : V) {
			for (int i = 0; i < A[s]; i++) {
				int p = x[s][i];
				if (info[p] != y[s][i]) {
					out = true;
					break;
				}
			}
		}
		if (out) continue;
		ans = max((int)V.size(), ans);
	}
	cout << ans << endl;
}