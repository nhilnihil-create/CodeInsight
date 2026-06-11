#pragma GCC optimize("Ofast")
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>

using namespace std;

#define ll long long
#define ull unsigned long long
const ll MOD = 1000000007;
#define rep(i,n) for (int i = 0; i < (n); ++i)

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
	ll N;
	cin >> N;

	map<ll, ll> m;
	bool ok = true;
	for (int ii = 0; ii < N; ++ii){
		ll A;
		cin >> A;
		if (m[A]){
			ok = false;
			break;
		}
		m[A] = 1;
	}

	if (ok){
	cout << "YES" << "\n";
	} else {
			cout << "NO" << "\n";
	}


	return 0;
}
