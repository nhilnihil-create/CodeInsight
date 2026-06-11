// IOI 2021
#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll MOD = 924844033;
 
////////////////////////////////////////////////////////////////////
 
const int N = 5e5 + 5;

int A[N];

int main() {
 
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mt19937 Rnd(time(0));

	string S; cin >> S;
	int n = sz(S);
	for (int i = 0; i < n; i++) if (S[i] == '<') A[i + 1] = max(A[i + 1], A[i] + 1);
	for (int i = n - 1; i >= 0; i--) if (S[i] == '>') A[i] = max(A[i], A[i + 1] + 1);
	ll sum = 0;
	for (int i = 0; i < n + 1; i++) sum += A[i];
	cout << sum << endl;

	return 0;
}
