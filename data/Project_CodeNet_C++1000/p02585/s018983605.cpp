#define _CRT_SECURE_NO_WARNINGS 1

#include <set>
#include <map>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define rep(i,a,b) for(int i = (a) ; i <= (b) ; i++)
#define per(i,a,b) for(int i = (a) ; i >= (b) ; i--)
#define mem(a) memset(a,0,sizeof(a))
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define fast_io ios::sync_with_stdio(false)

const LL INF = 1e18;
const LL mod = 1e9 + 7;
const int maxn = 5e3 + 7;

int p[maxn];
LL c[maxn];
LL sum[maxn];
vector<LL> v;

int main() {
	int n,k;
	sd(n),sd(k);
	rep(i,1,n) sd(p[i]);
	rep(i,1,n) slld(c[i]);
	LL ans = -INF;
	rep(i,1,n) {
		LL s = c[i];
		v.clear();
		v.push_back(s);
		for(int j = p[i] ; j != i ; j = p[j]) {
			// cout << "j = " << j << endl;
			s += c[j];
			v.push_back(s);
		}
		int len = v.size();
		rep(j,0,len-1) {
			LL res = k - j - 1;
			if(res < 0) break;
			ans = max(ans , v[j] + (res / len) * max(s,0LL));
		}
	}
	plld(ans);
	return 0;
}