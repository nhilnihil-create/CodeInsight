#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

#define INF LLONG_MAX / 5
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define enld endl

//各Q[i]を素因数分解した結果を２次元配列で返す。
//O(nlog(n)+Q.size()*log(Q[i]))
vector<vector<int>> multi_factolization(vector<int>Q) {
	vector<int>QQ = Q;
	sort(QQ);
	reverse(QQ);
	int n = QQ[0];
	vector<int> spf(n + 1);
	for (int i = 0; i <= n; i++) spf[i] = i;
	for (int i = 2; i * i <= n; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j <= n; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}
	vector<vector<int>>ANS(Q.size());
	rep(i, Q.size()) {
		vector<int> ret;
		while (Q[i] != 1) {
			ret.push_back(spf[Q[i]]);
			Q[i] /= spf[Q[i]];
		}
		sort(ret);
		ANS[i] = ret;
	}
	return ANS;
}

//aとbの最大公約数を返す
int gcd(int a, int b) {
	if (a < b)swap(a, b);
	if (a % b == 0)return b;
	return gcd(a % b, b);
}

//aとbの最小公倍数を返す
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

signed main() {
	int N;
	cin >> N;
	vector<int>A(N);
	rep(i, N) {
		cin >> A[i];
	}
	vector<vector<int>>V = multi_factolization(A);
	int GCD = A[0];
	rep(i, N) {
		GCD = gcd(GCD, A[i]);
	}
	if (GCD != 1) {
		cout << "not coprime" << enld;
		return 0;
	}

	vector<set<int>>S(N);
	rep(i, N) {
		rep(j, V[i].size()) {
			S[i].insert(V[i][j]);
		}
	}
	set<int>SS;
	rep(i, N) {
		for (auto x : S[i]) {
			if (SS.count(x)) {
				cout << "setwise coprime" << endl;
				return 0;
			}
			SS.insert(x);
		}
	}
	cout << "pairwise coprime" << enld;
}