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

const int INF = 1e9;
const LL mod = 1e9 + 7;
const int maxn = 5e5 + 7;

int main() {
	int k;
	sd(k);
	if(k % 2 == 0 || k % 5 == 0) puts("-1");
	else {
		int res = 7;
		for(int i = 1 ; ; i++) {
			if(res % k == 0) {
				pd(i);
				break;
			}
			res = (res * 10 + 7) % k;
		}
	}
	return 0;
}