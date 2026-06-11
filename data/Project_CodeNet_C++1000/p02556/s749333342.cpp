/*******
 *   Author: Quamputer
 *   
 * ******/
#include <bits/stdc++.h>

using namespace std;
 
#define int long long
 
#define PB	push_back
#define ALL(x)	(x).begin(), (x).end()
#define ALLR(x)	(x).rbegin(), (x).rend()
#define MP	make_pair

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
  return to_string((string) s);
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
  res += "}";
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
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
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
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
 
const int INF = LONG_LONG_MAX/2;
const double PI = 3.141592653589793238;
const int MOD = 1000000000 + 7;

#define x first
#define y second

bool many = false;
struct Solve {
	
	Solve() {
		int n;
		cin >> n;
		vii list(n);
		
		for (int i = 0; i < n; i++) {
			cin >> list[i].x >> list[i].y;
		}
		
		int mx1 = -INF;
		int mn1 = INF;
		int mx2 = -INF;
		int mn2 = INF;
		
		for (int i = 0; i < n; i++) {
			if (list[i].x + list[i].y >= mx1) {
				mx1 = list[i].x + list[i].y;
			}
			if (list[i].x + list[i].y <= mn1) {
				mn1 = list[i].x + list[i].y;
			}
			if (list[i].x - list[i].y >= mx2) {
				mx2 = list[i].x - list[i].y;
			}
			if (list[i].x - list[i].y <= mn2) {
				mn2 = list[i].x - list[i].y;
			}
		}
		
		cout << max(mx1-mn1, mx2 - mn2) << endl;
	}
};

signed main() {
	FAST_IO;
	int CASES=1;
	if (many)
		cin >> CASES;
	for (int i = 1; i <= CASES; i++) {
		Solve me;
	}
}
// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
