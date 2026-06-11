#define _CRT_SECURE_NO_WARNINGS 1

#include <set>
#include <map>
#include <stack>
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

const LL mod = 1e9 + 7;
const int maxn = 1e7 + 7;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);

LL a[maxn];

int main() {

#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	long _begin_time = clock();
#endif

    rep(i,1,maxn-7) {
        for(int j = i ; j <= maxn - 7 ; j += i) {
            a[j]++;
        }
    }
    int n;
    sd(n);
    LL ans = 0;
    rep(i,1,n) {
        ans += i * a[i];
    }
    plld(ans);
  
#ifndef ONLINE_JUDGE
	long _end_time = clock();
	// cout << "time = " <<  _end_time - _begin_time << endl;
#endif
    return 0;
}