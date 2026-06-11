#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include<cstdio>
#include <vector>
#include<queue>
#include<limits.h>
#include<string.h>
#include<functional>
#include<map>
#include<set>
#include<list>
#include<unordered_map>
#include<queue>
#define P pair<int,int>
using namespace std;

int a[100][100];
bool used[100];
signed main(){
	int b; cin >> b;
	for (int c = 0; c < b; c++) {
		for (int d = 0; d < b; d++) {
			cin >> a[c][d];
			if (a[c][d] == -1) {
				a[c][d] = INT_MAX / 3;
			}
		}
	}
	int ans = 0;
	priority_queue<P,vector<P>, greater<P>>Q;
	Q.push({ 0,0 });
	while (Q.size()) {
		P t = Q.top(); Q.pop();
		if (!used[t.second]) {
			ans += t.first;
			used[t.second] = true;
			for (int i = 0; i < b; i++) {
				Q.push({ a[t.second][i],i });
			}
		}
	}
	cout << ans << endl;
}