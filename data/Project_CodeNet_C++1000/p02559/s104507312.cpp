#include <chrono>
#include <iostream>
#include "bits/stdc++.h"
#include "atcoder/all"
using namespace atcoder;
using namespace std;
typedef long long ll;
#define int ll
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long double> vld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ld, ll> pldll;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vld;
#define newl '\n'
const ll M = 1e9 + 7;
const ll N = 1e2;
const ll INF = LONG_MAX;
#define ar array
#define REP(i, a, b) for (int i = a; i < b; i++)
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
#define LOG_TWO_N 10
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d = stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d = stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}

string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b ? "true" : "false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	FOR(sz(v))
		res += char('0' + v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
		res += char('0' + b[i]);
	return res;
}
template<class T> string to_string(T v) {
	bool f = 1;
	string res;
	EACH(x, v) {
		if (!f)
			res += ' ';
		f = 0;
		res += to_string(x);
	}
	return res;
}

template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) {
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) {
	write(h);
	if (sizeof...(t))
		write(' ');
	print(t...);
}

ll gcd(ll a, ll b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b % a, a);
    }
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
int f(char c)
{
    return (int)c - 96;
}

template <class T>
void print(vector<T> &vec, int inc = 0, bool lb = true)
{
    for (auto v : vec)
        cout << v + inc << " ";
    if (lb)
        cout << newl;
}

void solve(ll t1)
{
    int n,q; read(n,q);
    fenwick_tree<ll> ft(n);
    FOR(n) {
        int a; read(a);
        ft.add(i, a);
    }

    while(q--) {
        int t; read(t);
        if(t == 0) {
            int p, x; read(p, x);
            ft.add(p, x);
        } else {
            int l, r; read(l, r);
            cout << ft.sum(l, r);
        }
        cout << '\n';
    }
}

int32_t main()
{
    fast;

    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve(t);
    }

    return 0;
}