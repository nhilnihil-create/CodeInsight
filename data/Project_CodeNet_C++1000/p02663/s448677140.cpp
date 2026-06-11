#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_map>
#include <vector>
#define task ""
using namespace std;
using ll = long long;
using ld = long double;

const int N = 5e3 + 2;
int h1, m1, h2, m2, k;

void Read(){
	cin >> h1 >> m1 >> h2 >> m2 >> k;
}

void Solve(){
	int t1 = h1 * 60 + m1, t2 = h2 * 60 + m2;
	if(t1 >= t2)
		t2 += 60 * 24;
	cout << (t2 - t1) - k;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen(task".INP", "r", stdin);
//	freopen(task".OUT", "w", stdout);
	Read();
	Solve();
}
