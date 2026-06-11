#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s >> N;
	while (N) {
		map<string, int>m;
		m[s] = 0;
		int box = 1;
		while (1) {
			while (s.size() < N) {
				s += '0';
			}
			sort(s.begin(), s.end());
			string t = s;
			reverse(t.begin(), t.end());
			int a = 0, b = 0;
			for (int i = 0; i < N; i++) {
				a *= 10;
				b *= 10;
				a += s[i] - '0';
				b += t[i] - '0';
			}
			//cout << a << " " << b << endl;
			if (m.find(to_string(b - a)) == m.end()) {
				m[to_string(b - a)] = box;
			}
			else {
				cout << m[to_string(b - a)] << " " << b - a << " " << box - m[to_string(b - a)] << endl;
				break;
			}
			s = to_string(b - a);
			box++;
		}
		cin >> s >> N;
	}
	return 0;
}