#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000000;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

///////////////////////////





int main() {

	int N;

	cin >> N;

	ll x[200], y[200];
	repn(i, N) cin >> x[i] >> y[i];

	ll ans = 0;

	repn(i, N) {
		ll testx = y[i];
		ll testy = -x[i];

		ll nowx = 0;
		ll nowy = 0;
		repn(j, N) {
			if (x[j] * testx + y[j] * testy >= 0) {
				nowx += x[j];
				nowy += y[j];
				//cout << j<<" ";
			}
		}
		//cout << nowx << nowy << endl;

		ans = max(ans, nowx*nowx + nowy * nowy);

		//////////////////////////////////////

		repn(j, N) {
			if (x[i]*y[j]==x[j]*y[i]&&(x[i]*x[j]>0||y[i]*y[j]>0)) {
				nowx -= x[j];
				nowy -= y[j];
				//cout << j << " ";
			}
		}
		//cout << nowx << nowy << endl;

		ans = max(ans, nowx*nowx + nowy * nowy);

		//////////////////////////////////

		testx = -y[i];
		testy = x[i];

		nowx = 0;
		nowy = 0;
		repn(j, N) {
			if (x[j] * testx + y[j] * testy >= 0) {
				nowx += x[j];
				nowy += y[j];
				//cout << j<<" ";
			}
		}
		//cout << nowx << nowy << endl;

		ans = max(ans, nowx*nowx + nowy * nowy);

		///////////////////////////////////
		nowx = 0;
		nowy = 0;
		repn(j, N) {
			if (x[i] * y[j] == x[j] * y[i] && (x[i] * x[j] > 0 || y[i] * y[j] > 0)) {
				nowx -= x[j];
				nowy -= y[j];
				//cout << j << " ";
			}
		}
		//cout << nowx << nowy << endl;

		ans = max(ans, nowx*nowx + nowy * nowy);
	}

	cout << fixed << setprecision(13);

	cout << sqrt((double)ans);

	system("PAUSE");
}
