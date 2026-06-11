#include <bits/stdc++.h>
#define INF 114514810
#define FOR(i, r, n) for(int i=(r); i<(n); i++) 
#define REP(i, n) FOR(i, (0), n)

using namespace std;

int n;
bool p[100000], flg = 1;

int prime(){
	FOR(i, 2, 100000) p[i] = 1;
	REP(i, 100000) {
		if (p[i])
			for (int j = 2; i*j < 100000; j++) p[i*j] = 0;
	}
}

int main(){
	prime();
	cin >> n;
	int k = 2;
	cout << n << ":";
	while (k < 100000){
		if (n == 1) break;
		if (p[k])
			while (true){
				if (!(n%k)) {
					cout << " " << k;
					flg = 0;
					n /= k;
				}
				else break;
			}
		k++;
	}
	if (flg) cout << " " << n;
	cout << endl;
}