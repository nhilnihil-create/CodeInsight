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

typedef  long long int lint;

#define rep(i, n) for (lint i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define mp make_pair
#define enld endl

vector<lint> enum_div(lint n) {
	//nの約数を列挙
	vector<lint> ret;
	for (lint i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			if (i != n) {
				ret.push_back(i);
			}
			if (i * i != n) {
				if (n/i != n) {
					ret.push_back(n / i);
				}
			}
		}
	}
	return ret;
}

int main() {
	lint cnt = 0;
	lint N;
	cin >> N;
	vector<lint>A(N);
	rep(i, N) {
		cin >> A[i];
	}

	lint Z = pow(10, 6) + 3;
	vector<lint>B(Z);

	rep(i, N) {
		B[A[i]]++;
	}

	set<lint>S;
	rep(i, N) {
		S.insert(A[i]);
	}
	rep(i, N) {
		vector<lint>V;
		V = enum_div(A[i]);
		bool flag = false;
		rep(j, V.size()) {
			if (S.count(V[j])) {
				flag = true;
			}
		}

		if (B[A[i]] != 1) {
			flag = true;
		}

		if (flag == false) {
			cnt++;
		}
	}
	cout << cnt << endl;
}