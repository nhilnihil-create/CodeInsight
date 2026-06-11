#include <bits/stdc++.h>

using namespace std;

inline int ctoi(char c) { if(c < '0' || '9' < c) throw invalid_argument("ctoi error"); return c - '0'; }
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

template <typename T>
inline T gcd(T x, T y){
	if (x <= 0 || y <= 0) throw invalid_argument("gcd error: x <= 0 or y <= 0");
	
	if(x < y) swap(x, y);
	T r = x % y;

	while(r != 0){
		x = y;
		y = r;
		r = x % y;
	}

	return y;
}
template <typename T>
inline T lcm(T x, T y){
	if (x <= 0 || y <= 0) throw invalid_argument("lcm error: x <= 0 or y <= 0");

	return x * y / gcd(x, y);
}

int main(){
	int n;
	cin >> n;

	vector<int> input(n);
	rep(i, n){
		cin >> input[i];
	}

	long long int ans = 0;
	int h = input[0];

	REP(i, 1, n){
		if(max(input[i - 1], h) > input[i]) ans += max(input[i - 1], h) - input[i];

		h = max(input[i], h);
	}

	cout << ans;

	return 0;
}