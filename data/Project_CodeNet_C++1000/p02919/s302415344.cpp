#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;i<(n);i++)
#define rrep(i,n) for(int (i)=1;i<=(n);i++)
#define REP(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define MOD 1000000007
#define INF 1e18
#define fcout cout << fixed << setprecision(15)
#define int long long
#define endl "\n"
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)?"YES":"NO")
typedef long long ll;
typedef pair<int, int> P;
int gcd(int a,int b){return b?gcd(b,a%b):a;};
int lcm(int a,int b){return a/gcd(a,b)*b;};
int mod(int a,int b){return (a+b-1)/b;};
template<typename A, size_t N, typename T>
void Fill(A(&array)[N],const T &val){std::fill((T*)array,(T*)(array+N),val);}
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;};
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;};

int l[100005], r[100005], w[100005];

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int x;
	rrep(i, n) {
		cin >> x;
		w[x] = i;
		l[i] = i-1;
		r[i] = i+1;
	}

	int ans = 0;
	rrep(i, n) {
		int b = l[w[i]], a = l[b];
		int c = r[w[i]], d = r[c];
		if(b) ans += (b - a) * (c - w[i]) * i;
		if(c != n+1) ans += (d - c) * (w[i] - b) * i;
		l[c] = b;
		r[b] = c;
	}
	cout << ans << endl;
	return 0;
}