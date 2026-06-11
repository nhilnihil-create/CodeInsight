#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, A, c[300000], s[300000], res, p;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		c[A - 1]++;
	}
	sort(c, c + N);
	s[0] = c[0];
	for (int i = 1; i < N; i++) {
		s[i] = s[i - 1] + c[i];
	}
	res = N;
	p = N - 1;
	for (int i = 1; i <= N; i++) {
		while ((s[p] + (N - 1 - p)*res) / i < res) {
			res--;
			while (p&&c[p] >= res) {
				p--;
			}
		}
		cout << res << endl;
	}
}