//#include "bits/stdc++.h"

#define _USE_MATH_DEFINES
#include<cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include<iomanip>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

//typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

int N, BN;
int S[300010];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	BN = 1 << N;
	int maxs = 0;
	multiset<int> sset;
	rep(i, 0, BN)
	{
		cin >> S[i];
		chmax(maxs, S[i]);
		sset.insert(S[i]);
	}

	vector<int> C;
	C.push_back(maxs);
	sset.erase(sset.find(maxs));

	rep(i, 0, N)
	{
		vector<int> TC;
		for (auto c : C)
		{
			auto itr = sset.lower_bound(c);
			if (itr == sset.begin())
			{
				cout << "No" << endl;
				return 0;
			}
			itr--;
			TC.push_back(*itr);
			sset.erase(itr);
		}
		rep(j, 0, SZ(TC))
		{
			C.push_back(TC[j]);
		}
		sort(all(C), greater<int>());
	}

	cout << "Yes" << endl;

	return 0;
}