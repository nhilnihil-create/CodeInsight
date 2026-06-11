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

int main() {
	lint A, B, C;
	cin >> A >> B >> C;
	lint K;
	cin >> K;
	lint cnt = 0;
	while (1) {
		if (A < B) {
			break;
		}
		else {
			B *= 2;
			cnt++;
		}
	}
	while (1) {
		if (B < C) {
			break;
		}
		else {
			C *= 2;
			cnt++;
		}
	}
	if (cnt <= K) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}