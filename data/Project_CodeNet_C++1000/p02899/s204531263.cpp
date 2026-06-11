// #include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,x,n) for(int i=x;i<n;i++)
#define exrep(x,vec) for(auto&& x : vec);
#define PI 3.14159265358979323846264338327950288
const int MOD{ int(1e9 + 7) };	// = 1000000007
const int inf{ 2100000000 };	// = 2100000000 (MAX:2147483647)
typedef long long ll;
using namespace std;

// -------------------------------------------------- //
// ------------------ ここから本編 ------------------ //
// -------------------------------------------------- //

int main(void) {

	int N; cin >> N;
	vector<pair<int, int>> p(N);
	rep(i, N) {
		cin >> p[i].first;
		p[i].second = i;
	}

	sort(p.begin(), p.end());
	
	rep(i, N) {
		cout << p[i].second + 1 << " ";
	}
	cout << endl;
	return 0;
}
