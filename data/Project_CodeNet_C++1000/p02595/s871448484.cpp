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
const int maxn = 1e3 + 7;

int main() {
	int n;
	LL d;
	cin >> n >> d;
	LL ans = 0;
	rep(i,1,n) {
		LL x,y;
		cin >> x >> y;
		if(x * x + y * y <= d * d) ans++;
	}
	cout << ans << endl;
	return 0;
}