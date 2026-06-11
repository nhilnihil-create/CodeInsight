#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const ll mod = 1000000007;
const int inf = 0x3f3f3f3f;
const ll inff = 0x7ffffffffff;
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
//head
const int N = 10;
int n, m, k, ans;
char ch[N][N];
int g[N][N];
int main() {
	cin >> n >> m >> k;
	rep(i, 1, n) {
		rep(j, 1, m) {	
			cin >> ch[i][j];
			if(ch[i][j] == '#') g[i][j] = 1;
		}
	}
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < (1 << m); j++) {
			int cnt = 0;
			for (int x = 1; x <= n; x++) {
				for (int y = 1; y <= m; y++) {
					if((1 << (x - 1)) & i) continue;
					if((1 << (y - 1)) & j) continue;
					cnt += g[x][y];
				}
			}
			if(cnt == k) ++ans;
		}
	}
	printf("%d", ans);
	return 0;
}