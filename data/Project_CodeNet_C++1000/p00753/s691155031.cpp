#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define INF 1000000000
#define rep(i,a,b) for (int i=(a);i<(b);i++)
#define rev(i,a,b) for (int i=(a)-1;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef queue<int> qi;
typedef vector<int> vi;
typedef vector<string> vs;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

const int M = 123456 * 2;
bool prime[M];

int main() {

	rep(i,0,M) prime[i] = true;
	rep(i,2,sqrt(M)) {
		if(prime[i])
			for(int j = 0; i * (j + 2) < M; j++)
				prime[i *(j + 2)] = false;
	}

	while(true) {
		int n;
		cin >> n;
		if(!n) break;

		if(n == 1) {
			cout << 1 << endl;
			continue;
		}

		int ans = 0;
		rep(i,n+1,2*n) if(prime[i]) ans++;
		cout << ans << endl;
	}

	return 0;
}