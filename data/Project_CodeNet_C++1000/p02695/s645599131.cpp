#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 11, maxq = 51;
struct query { int a, b, c, d; } q[maxq];
int n, m, k, a[maxn];
int best = 0;
void bt(int i, int mn){
	if (i == n+1){
		int cand = 0;
		for(int j = 0; j<k; j++){
			query&t = q[j];
			cand += t.d * (a[t.b] - a[t.a] == t.c);
		}
		best = max(best, cand);
		return;
	}
	for(int j = mn; j<=m; j++){
		a[i] = j;
		bt(i+1, j);
		a[i] = -1;
	}


}

int main(){
	cin >> n >> m >> k;
	for(int i = 0; i<k; i++){
		cin >> q[i].a >> q[i].b >> q[i].c >> q[i].d;
	}
	bt(1, 1);
	cout << best << endl;
	return 0;
}