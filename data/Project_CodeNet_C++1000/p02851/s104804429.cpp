#include <iostream>
#include <fstream>
#include <utility>
#include <queue>
#include <vector>
#include <array>
#include <stack>
#include <list>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define bs(n) (1ul<<(n))

ll n, k, s[200001], r = 0;
map<ll, ll> t;

int main() {
	cin >> n >> k;
	auto g = []() {ll a; cin >> a; return a; };
	rep(i, n)s[i + 1] = (s[i] + g() - 1) % k;
	rep(i, n + 1) {
		if (i >= k) t[s[i - k]]--;
		r += t[s[i]];
		t[s[i]]++;
	}
	cout << r << endl;
}
