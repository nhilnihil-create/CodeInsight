#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << endl
#else
#define debug(x)
#endif
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

int K, Q;
ll d[5000], d2[5000];
ll sum = 0;

signed main(){
	cin >> K >> Q;
	rep(i, K){
		cin >> d[i];
		sum += d[i];
	}

	rep(q, Q){
		ll n, x, m;
		cin >> n >> x >> m;
		x %= m;

		ll ans = 0;

		ll c = 0;
		ll now = 0;
		rep(i, K){
			if(now < (now+d[i])%m) c++;
			now += d[i];
			now %= m;
		}

		ll T = (n-1) / K;
		ans = c * T - (x+(sum%m)*T)/m;
		//cout << ans << endl;

		now = x + (sum%m)*T;
		now %= m;
		rep(i, (n-1) % K){
			if(now < (now+d[i])%m) ans++;
			now += d[i];
			now %= m;
		}
		cout << ans << endl;
	}
}
/*
5 26
1 2 4 2 3
2 0 5
3 0 5
4 0 5
5 0 5
6 0 5
7 0 5
8 0 5
9 0 5
10 0 5
11 0 5
12 0 5
13 0 5
14 0 5
15 0 5
16 0 5
17 0 5
18 0 5
19 0 5
20 0 5
21 0 5
22 0 5
23 0 5
24 0 5
25 0 5
26 0 5
27 0 5

//84
7 1
3 6 4 6 4 10 4
76 3 12
*/