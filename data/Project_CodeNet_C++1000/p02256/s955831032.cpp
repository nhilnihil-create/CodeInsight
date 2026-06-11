#include <bits/stdc++.h>
#define INF 114514810
#define FOR(i, r, n) for(int i=(r); i<(n); i++) 
#define REP(i, n) FOR(i, (0), n)

using namespace std;

long long int a, b;

int gcd(int m, int n){
	if (!m || !n) return 0;
	while (m != n){
		if (m > n) m -= n;
		else n -= m;
	}
	return m;
}

int main(){
	cin >> a >> b;
	cout << gcd(a, b) << endl;
}