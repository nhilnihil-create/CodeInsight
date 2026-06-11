#include <bits/stdc++.h>

using namespace std;
using lli = int_fast64_t;
using ulli = unsigned long long;
#define debug(x) cerr << #x << " : " << x << endl
#define debugv(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x << ", ";}cerr << endl
#define debugst(x) auto xt = copy(x);cerr << #x << " : {";for(int i=0;i<x.size();i++){ cerr << xt.top() << ", ";xt.pop();}cerr << endl
#define debugvp(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x.first << " : " << value_of_x.second << ", ";}cerr << endl

constexpr lli MOD = (lli)1e9 + 7;
constexpr lli LIMIT = 1000000000000000000 * 5;

constexpr lli plusScore = (lli)1e6;
constexpr size_t D = 365;
constexpr size_t asize = 26;

array<lli, asize> C;
array<array<lli,asize>,D> S;

lli calcScore(const vector<lli>& t) {
	vector<lli> last_open(asize, -1);
	lli score = 0;
	for (int i = 0; i < D; i++) {
		score += S[i][t[i] - 1];
		last_open[t[i] - 1] = i;
		for (int j = 0; j < asize; j++) {
			score -= C[j] * (i - last_open[j]);
		}
		cout << score << endl;
	}
	return score;
};

int main() {
	int devNull;
	cin >> devNull;
	for (lli& i : C)cin >> i;
	for (auto& arr : S) {
		for (lli& i : arr) {
			cin >> i;
		}
	}

	vector<lli> T(D);
	for (lli& i : T)cin >> i;

	vector<int> lastOpen(asize, -1);

	calcScore(T);

	//
	//int M;
	//cin >> M;
	//while (M--) {
	//	int d, q;
	//	cin >> d >> q;
	//	T[d-1] = q;
	//	cout << calcScore(T) << endl;
	//}
	return 0;
}

