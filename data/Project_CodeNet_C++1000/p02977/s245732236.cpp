#include "bits/stdc++.h"

using namespace std;

#define int long long
#define ll long long
typedef pair<int, int> P;
#define mod 1000000007
#define INF (1LL<<60)

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define YES puts("YES\n")
#define Yes puts("Yes\n")
#define NO  puts("NO\n")
#define No  puts("No\n")
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }


signed main() {

	int N;
	cin >> N;

	// N=1,2,4,8,はNG
	bool power = false;
	for (int i = 1; i > 0; i *= 2)
		if (N == i) { power = true;  break; }

	if (power == true) {
		No; return 0;
	}

	auto print = [](int a, int b) { cout << a << " " << b << endl; };

	Yes;

	print(1, 2);
	print(2, 3);
	print(3, 1 + N);
	print(1 + N, 2 + N);
	print(2 + N, 3 + N);

	for (int i = 4; i <= N-1; i += 2) {
		print(i, i + 1);
		print(i + 1, 1+N);
		print(1+N, i+N);
		print(i + N, i + 1 + N);
	}

	if (N % 2 == 0) {
		for (int i = 2; i <= N - 1; i++) {
			int b = (i ^ 1 ^ N);
			if (b <= N - 1 && i != b) {
				cerr << endl;
				cerr << i << endl;
				cerr << (i ^ 1 ^ N) << endl;
				cerr << endl;
				if (i % 2 == 0) {
					print(N, i + N);
//					print(i + N, 1+N);
				}else {
					print(N, i);
//					print(i, 1+N);
				}
				if (b % 2 == 0) {
					print(b + N, N + N);
				}
				else {
					print(b, N + N);
				}
				return 0;
			}
		}
	}
	
	return 0;
}