#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 998244353;
const ll MAX = 1000000;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

//gcd,lcm,べき,二進展開
//組み合わせ、mod計算
//最短路問題、bit、union find

///////////////////////////



	
int main() {

	ll N;
	cin >> N;
	ll M = pow(2, N);

	ll S[MAX];

	repn(i, M) cin >> S[i];
	sort(S + 1, S + M + 1, greater<ll>());

	priority_queue<ll> p[20];

	rep(i, N) { p[i].push(S[1]); }

	string ans = "Yes";

	for (int i = 2; i <= M; i++) {
		for (int j = N-1; j >= 0; j--) {

			if (!p[j].empty()) {
				ll v = p[j].top();
				if (v > S[i]) {
					p[j].pop();
					rep(k, j) { p[k].push(S[i]); }
					break;
				}
			}

			if (j == 0) { ans = "No"; }

		}


		if (ans == "No") { break; }

	}

	cout << ans;
	

	system("PAUSE");


}