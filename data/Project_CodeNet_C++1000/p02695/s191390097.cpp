#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <math.h> 
#include <iomanip>
#include <string.h>
#include<sstream>
#include <vector>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define PI 3.14159265358979323846264338327950L

#define INF 0x3f3f3f3f
//const int N = 2e5 + 5;

 
int a[51], b[51], c[51],q[51];
int N, M, Q;

int ans = 0;

vector<int> v;

int check() {
	int total = 0;
	for (int i = 0; i < Q; i++) {

		if (v[b[i]] - v[a[i]] == c[i]) {

			total += q[i];

		}

	}
	return total;
}

void dfs(int i, int cur) {

	if (i >= N) {

		ans = max(ans, check());
		return;
	}
	 
	for (int j = cur; j <= M; j++) {

		v.push_back(j);
		dfs(i + 1, j);
		v.pop_back();
	}

}


int32_t  main() {

	IOS;
  
  
 
	cin >> N >> M >> Q;


	for (int i = 0; i < Q; i++) {

		cin >> a[i] >> b[i] >> c[i] >> q[i] ;
		a[i]--;
		b[i]--;
	}

	dfs(0, 1);

	cout << ans << endl;
}