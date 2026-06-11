#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using msi = map<string, int>;
using mii = map<int, int>;
using psi = pair<string, int>;
using pii = pair<int, int>;
using vlai = valarray<int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 1E9
#define EPS 1E-9
#define MOD (1E9+7)
#define PI 3.1415926535897932384626433832795

int n;

void printcomp(complex<double> c) {
	printf("%.8lf %.8lf\n", c.real(), c.imag() );
}


void rec(int level, complex<double> s, complex<double> e) {
	if (level >= n)return;
	complex<double> p1, p2, p3;
	p1 = s + (e - s) / 3.0;
	p3 = s + (e - s) * 2.0 / 3.0;
	p2 = p1 + (p3 - p1)*exp(complex<double>(.0, 60.0 * PI / 180.0));
	rec(level + 1, s, p1);
	printcomp(p1);
	rec(level + 1, p1, p2);
	printcomp(p2);
	rec(level + 1, p2, p3);
	printcomp(p3);
	rec(level + 1, p3, e);
}

int main() {
	cin >> n;
	complex<double> s(.0,.0), e(100.0,.0);
	printcomp(s);
	rec(0,s,e);
	printcomp(e);
}
