#define LOCAL

#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define LLINF 1e18
#define INF (int)1e9+1

// Copied from Gennady-Korotkevich's template

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string)s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}\n";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto& x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}\n";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + "," + to_string(get<4>(p)) + ")";
}

void debug_out() {
	cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "\n[" << #__VA_ARGS__ << "]:\n", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// End of Gennady-Korotkevich's template 

using llong = long long;
using PII = pair<int, int>;

const llong MOD = 998244353LL;

int main() {
	IOS;
	int h, w, k;
	cin >> h >> w >> k;
	vector<vector<int>> f(h, vector<int>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char c; cin >> c;
			if (c == '.') f[i][j] = 1;
			else f[i][j] = 2;
		}
	}
	int realAns = 0;
	for (int colMask = 0; colMask < (1 << w); colMask++) {
		for (int rowMask = 0; rowMask < (1 << h); rowMask++) {
			int tempCol = colMask, tempRow = rowMask;
			vector<vector<int>> temp = f;
			int cnt = 0;
			while (tempCol > 0) {
				if (tempCol % 2) for (int i = 0; i < h; i++) temp[i][cnt] = 0;
				tempCol /= 2; cnt++;
			}
			cnt = 0;
			while (tempRow > 0) {
				if (tempRow % 2) for (int i = 0; i < w; i++) temp[cnt][i] = 0;
				tempRow /= 2; cnt++;
			}
			cnt = 0;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (temp[i][j] == 2) cnt++;
				}
			}
			if (cnt == k) realAns++;
		}
	}
	cout << realAns;
}