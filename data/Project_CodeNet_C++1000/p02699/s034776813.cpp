/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<limits.h>
#include<cmath>
#include<queue>
#include<stack>

#include<stdio.h>
#include<stdlib.h>

#define rep(i,n) for(ll i = 0; i < (ll)n; i++)
#define swap(a,b) a^=b;b^=a;a^=b;
#define chmax(a,b) {if(a < b) a = b;}
#define chmin(a,b) {if(a > b) a = b;}

using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

ll factor(ll x) {
	ll ret = 1;
	ll tmp = 0;
	for (ll p = 2;;p++) {
		if (x == 1) {
			ret *= tmp + 1;
			break;
		}
		if (x % p == 0) {
			tmp += 1;
			x /= p;
			p--;
			continue;
		}
		ret *= tmp + 1;
		tmp = 0;
	}
	return ret;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//Program Start

	ll N;
	cin >> N;
	ll ans = 0;

	for (ll i = 1; i <= N; i++) {
		ll ret = factor(i);
		ll tmp = ret;
		ans += i * tmp;
	}

	cout << ans << endl;



EndPoint:;

	//Program End
#ifndef DEBUG
	system("pause");
#endif // !DEBUG

	return 0;
}


*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<limits.h>
#include<cmath>
#include<queue>
#include<stack>

#include<stdio.h>
#include<stdlib.h>

#define rep(i,n) for(ll i = 0; i < (ll)n; i++)
#define swap(a,b) a^=b;b^=a;a^=b;
#define chmax(a,b) {if(a < b) a = b;}
#define chmin(a,b) {if(a > b) a = b;}

using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//Program Start	


	int S, W;
	cin >> S >> W;

	if (S <= W) {
		cout << "unsafe" << endl;
	}
	else {
		cout << "safe" << endl;
	}

EndPoint:;

	//Program End
#ifndef DEBUG
	system("pause");
#endif // !DEBUG

	return 0;
}


