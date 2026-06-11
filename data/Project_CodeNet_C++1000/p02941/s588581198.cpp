#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, A[200000], B[200000];
ll cnt;
priority_queue<pair<int, int>>q;
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
		if (A[i] != B[i]) {
			q.push(mkp(B[i], i));
		}
		if (A[i] > B[i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	while (true) {
		if (q.size() == 1) {
			int x = q.top().first;
			int y = q.top().second;
			if ((x - A[y]) % (B[(y + N - 1) % N] + B[(y + 1) % N]) == 0) {
				cnt += (x - A[y]) / (B[(y + N - 1) % N] + B[(y + 1) % N]);
				cout << cnt << endl;
				return 0;
			}
			else {
				cout << -1 << endl;
				return 0;
			}
		}
		else {
			int x = q.top().first;
			int y = q.top().second;
			if (A[y] >= max(B[(y + N - 1) % N], B[(y + 1) % N])) {
				if ((x - A[y]) % (B[(y + N - 1) % N] + B[(y + 1) % N]) == 0) {
					cnt += (x - A[y]) / (B[(y + N - 1) % N] + B[(y + 1) % N]);
					q.pop();
					B[y] = A[y];
				}
				else {
					cout << -1 << endl;
					return 0;
				}
			}
			else {
				cnt += (x - max(B[(y + N - 1) % N], B[(y + 1) % N])) / (B[(y + N - 1) % N] + B[(y + 1) % N]) + 1;
				B[y] -= ((x - max(B[(y + N - 1) % N], B[(y + 1) % N])) / (B[(y + N - 1) % N] + B[(y + 1) % N]) + 1)*(B[(y + N - 1) % N] + B[(y + 1) % N]);
				if (B[y] < A[y]) {
					cout << -1 << endl;
					return 0;
				}
				q.pop();
				if (B[y] != A[y]) {
					q.push(mkp(B[y], y));
				}
			}
		}
	}
}
