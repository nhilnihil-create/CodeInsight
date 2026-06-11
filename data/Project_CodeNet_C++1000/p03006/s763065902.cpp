#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#define N 55
using namespace std;

typedef long long ll;
ll n, M = 1e9, Z = 2e9 + 1, tc, s, mn = -1, dx, dy, x[N], y[N], v[N];
map<ll, ll> e;
queue<ll> qu;
void ch(ll p, ll q) {
	ll t = p * Z + q, t2;
	t2 = e[t];
	if (t2 != 0 && v[t2] != tc) {
		v[t2] = tc;
		qu.push(t2);
	}
}

void f(ll p) {
    ll i;
    v[p] = tc;
    qu.push(p);
    while (!qu.empty()) {
		p = qu.front(); qu.pop();
		ch(x[p] + dx, y[p] + dy);
		ch(x[p] - dx, y[p] - dy);
    }
}

int main()
{
	ll i, j, k;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	for (i = 1; i <= n; i++) {
		scanf ("%lld %lld", &x[i], &y[i]);
		x[i] += M;
		y[i] += M;
		e[(x[i] * Z) + y[i]] = i;
	}
	for (i =1; i <= n; i++) {
		for (j = i + 1; j <= n; j++) {
            tc++;
            dx = x[j] - x[i];
            dy = y[j] - y[i];
            f(i);
            s = 1;
            for (k = 1; k <= n; k++) {
				if (v[k] != tc) {f(k); s++;}
            }
            if (mn == -1 || s < mn) mn = s;
		}
	}
	cout << mn << endl;
    return 0;
}
