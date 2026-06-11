#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<map>
#include<unordered_map>

#define ll long long
#define pll pair<ll,ll>

using namespace  std;
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}
ll qpow(ll a, ll b, ll modd) {
	ll ans = 1, base = a;
	while (b) {
		if (b & 1) {
			ans = (ans*base) % modd;
		}
		base = (base*base) % modd;
		b >>= 1;
	}
	return ans;
}

/*A*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//}

//****************************************************************************
/*B*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//
//}

//****************************************************************************
/*C*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//
//}

//****************************************************************************
/*D*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//
//}

//****************************************************************************
/*E*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//
//}

//****************************************************************************
/*F*/
//vector<pll> v ;
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n; cin >> n;
//	for (int i = 1; i <= n; ++i) {
//		int tmp;
//		cin >> tmp;
//		v.push_back(make_pair(tmp, i));
//	}
//	sort(v.begin(), v.end());
//	for (int i = 0; i < n; ++i) {
//		cout << v[i].second << ' ';
//	}
//}


//****************************************************************************
/*G*/
//const int N = 1e6 + 5;

//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	
//	ll a, b;
//	cin >> a >> b;
//	//getprime();
//	ll l = gcd(a, b);
//	if (l == 1) {
//		cout << 1; return 0;
//	}
//
//	ll cnt = 0;
//	ll limit = sqrt(l + 0.5);
//	for (ll i = 2; i <= limit; ++i) {
//		if (l%i == 0) {
//			cnt++;
//			while (l%i == 0) {
//				l /= i;
//			}
//		}
//	}
//	if(l>1) cnt++;
//	cout << cnt + 1 ;
//}

//****************************************************************************
/*H*/
//int ktob[1005];
//int a[1005], b[1005];
//int dp[1005][(1<<12)];
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n,m; cin >> n>>m;
//	for (int i = 1; i <= m; ++i) {
//		cin >> a[i] >> b[i];
//		for (int j = 1; j <= b[i]; ++j) {
//			int tmp;
//			cin >> tmp;
//			ktob[i] |= (1 << (tmp - 1));
//		}
//	}
//	
//	memset(dp, 0x3f, sizeof(dp));
//	dp[0][0] = 0;
//	for (int i = 1; i <= m; ++i) {
//		for (int j = 0; j <= (1 << n)-1; ++j) {
//			dp[i][j] = min(dp[i][j],dp[i-1][j]);
//			dp[i][j | ktob[i]] = min(dp[i][j | ktob[i]], dp[i-1][j] + a[i]);
//		}
//	}
//	cout << ((dp[m][(1 << n) - 1]==0x3f3f3f3f)?-1: dp[m][(1 << n) - 1]);
//}

//****************************************************************************
/*I*/
//int L[2050];
//typedef struct node {
//	int a, b, c;
//	bool operator<(const struct node &x) const{
//		return a < x.a;
//	}
//}Node;
//set<Node> s;
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n; cin >> n;
//	for (int i = 1; i <= n; ++i) {
//		cin >> L[i];
//	}
//	sort(L + 1, L + n + 1);
//	int cnt = 0;
//	for (int i = 1; i < n - 1; i++) {
//		int a = L[i];
//		for (int j = i + 1; j < n; ++j) {
//			int b = L[j];
//			for (int k = j + 1; k <= n; ++k) {
//				int c = L[k];
//				if (a < b + c && b < c + a && c < a + b) {
//					cnt++;
//				}
//			}
//		
//		}
//	}
//	cout << cnt;
//}

//****************************************************************************

/*J*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//
//}

//****************************************************************************

/*K*/
const int N = 3e5 + 5;

int acnt[N],a[N];
int res[N];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	for (int i =1; i <= n; ++i) {
		int tmp; cin >> tmp;
		a[tmp]++;
	}

	for (int i = 1; i <= n; ++i) {
		acnt[a[i]]++;
	}

	for (int i = n; i >=1; --i) {
		acnt[i]+=acnt[i+1];
	}
	int ans = 0;
	ll cnt = 0;
	for (ll i = n; i >= 1; --i) {
		while ((cnt + (int)acnt[ans+1]) >= i * (ans + 1)) {
			cnt += acnt[++ans];
		}
		res[i] = ans;
	}
	for (int i = 1; i <= n; ++i) {
		cout << res[i] << '\n';
	}
}

//****************************************************************************

/*L*/
//const int N = 1e5 + 5;
//ll a[N],b[N];
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n; cin >> n;
//	ll sum = 0;
//	for (int i = 1; i <= n; ++i) {
//		cin >> a[i];
//		if (i % 2) {
//			sum += a[i];
//		}
//		else {
//			sum -= a[i];
//		}
//	}
//
//	cout << sum << ' ';
//
//	
//	for (int i = 2; i <= n; ++i) {
//		sum = 2*a[i - 1] - sum;
//		cout << sum << " ";
//	}
//
//}

//****************************************************************************

/*M*/
//const int N = 1e5 + 5;
//int a[N];
//
//ll C(ll n, ll m) {
//	
//}
//int main() {
//	//ios::sync_with_stdio(0); cin.tie(0);
//	int t; scanf("%d", &t);
//	while (t--) {
//		int n;  scanf("%d", &n);
//		for (int i = 1; i <= n; ++ i) {
//			scanf("%d", a+i);
//		}
//		ll fm = C(4, 3);
//	}
//}

//****************************************************************************