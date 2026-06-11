#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
//#define co(x) cout << (x) << "\n"
//#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please

const int dm = 1 << 22;
char dn[dm], * di = dn;
inline void cosp(int X) {
	int keta = 0;
	char C[10];
	while (X) {
		*(C + keta) = '0' + X % 10;
		X /= 10;
		keta++;
	}
	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));
	*di++ = ' ';
}
inline void co(int X) {
	int keta = 0;
	char C[10];
	while (X) {
		*(C + keta) = '0' + X % 10;
		X /= 10;
		keta++;
	}
	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));
	*di++ = '\n';
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;

	if (N == 1) * di++='N', * di++ = 'o', * di++ = '\n';
	else {
		bool dame = false;
		int k = 1;
		rep(i, 20) {
			k *= 2;
			if (N == k) dame = true;
		}
		if (dame)* di++ = 'N', * di++ = 'o', * di++ = '\n';
		else if (N % 2 == 0) {
			*di++ = 'Y';
			*di++ = 'e';
			*di++ = 's';
			*di++ = '\n';
			int xs = 0;
			rep1(i, N) {
				xs ^= i;
			}
			int a = N - 1;
			int b = xs ^ a;
			int c = a ^ 1;
			int d = b ^ 1;

			cosp(c);
			co(1);
			cosp(a);
			co(c);
			cosp(1);
			co(a + N);

			cosp(1);
			co(d);
			cosp(b);
			co(d);
			cosp(1);
			co(b + N);

			int mae = d;
			rep1(i, N) {
				if (i != a && i != b && i != c && i != d && i != 1) {
					cosp(mae);
					co(i);
					mae = i;
				}
			}
			cosp(mae);
			co(c + N);
			mae = c + N;
			cosp(mae);
			co(1 + N);
			mae = 1 + N;
			cosp(mae);
			co(d + N);
			mae = d + N;
			rep1(i, N) {
				if (i != a && i != b && i != c && i != d && i != 1) {
					cosp(mae);
					co(i + N);
					mae = i + N;
				}
			}
		}
		else {
			*di++ = 'Y';
			*di++ = 'e';
			*di++ = 's';
			*di++ = '\n';
			rep1(i, N / 2) {
				int k = i * 2;
				cosp(1);
				co(k);
				cosp(k);
				co(k + 1);
				cosp(1);
				co(k + N + 1);
				cosp(k + N);
				co(k + N + 1);
			}
			cosp(1 + N);
			co(2 + N);
		}
	}

	fwrite_unlocked(dn, di - dn, 1, stdout);
	Would you please return 0;
}