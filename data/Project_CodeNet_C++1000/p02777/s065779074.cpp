#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

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
	string S, T;
	cin >> S >> T;
	int A, B;
	cin >> A >> B;
	string U;
	cin >> U;

	if (S == U){
		cout << A-1 << " " << B << "\n";
	} else {
		cout << A << " " << B-1 << "\n";		
	}

	return 0;
}
