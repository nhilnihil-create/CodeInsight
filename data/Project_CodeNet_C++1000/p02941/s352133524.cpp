#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ scanf("%d%d",&x.first, &x.second); }
void read(pll& x){ scanf("%lld%lld",&x.first, &x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = int(2e5) + 10;

int n;
int a[maxn];
int b[maxn];

int main()
{
	cppio();
	cin >> n;
	rrep(i, n) cin >> a[i];
	rrep(i, n) cin >> b[i];

	priority_queue<pp> pq;
	rrep(i, n) pq.emplace(b[i], i);

	ll cnt = 0;
	while(pq.size()) {
		int x, i; tie(x, i) = pq.top(); pq.pop();
		//printf("pop i %d x %d (b %d)\n", i, x, b[i]);
		if(b[i] != x) continue;

		if(b[i] < a[i]) {
			cout << -1 << '\n';
			return 0;
		}

		if(b[i] == a[i]) continue;

		int i1 = (i+n-2)%n + 1;
		int i2 = i%n + 1;

		int df = (b[i1] + b[i2]);
		int c = (b[i] - max({a[i], b[i1] + b[i2]}) + df - 1) / df;

		if(c == 0) continue;

		//printf("b: %d (%d) %d / df %d, c %d\n", b[i1], b[i], b[i2], df, c);

		cnt += c;
		b[i] -= df * c;

		pq.emplace(b[i], i);
	}

	rrep(i, n) if(a[i] != b[i]) {
		cout << -1 << '\n';
		return 0;
	}

	cout << cnt << endl;
	return 0;
}
