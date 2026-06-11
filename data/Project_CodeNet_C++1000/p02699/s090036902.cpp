#include <bits/stdc++.h>
using namespace std;

//constexpr long double PIL = 3.141592653589793238462643383279502884L;
//constexpr double PI = 3.14159265358979323846;

#define sz(a) (int)((a).size())
#define all(c) (c).begin(), (c).end()
#define debug(v) {for (auto z : v) {cerr << z << ' ';} cerr << endl;}

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int,int>>;

const ll MOD = 1e9 + 7;

int main() {
	int s, w;
	cin >> s >> w;
	cout << (w >= s ? "unsafe" : "safe") << '\n';
}
