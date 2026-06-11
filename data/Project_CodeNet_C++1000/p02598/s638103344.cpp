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
    const int maxn = 2e5 + 7;
     
    int a[maxn];
    int n,k;
     
    bool check(int mid) {
    	int res = 0;
    	rep(i,1,n) {
    		if(a[i] <= mid) continue;
    		res += a[i] / mid;
    	}
    	return res <= k;
    }
     
    int main() {
    	sd(n), sd(k);
    	rep(i,1,n) sd(a[i]);
    	int l = 1, r = INF;
    	int ans = 0;
    	while(l <= r) {
    		int mid = (l + r + 1) >> 1;
    		// cout << "mid = " << mid << endl;
    		if(check(mid)) {
    			ans = mid;
    			r = mid - 1;
    		} else {
    			l = mid + 1;
    		}
    	}
    	pd(ans);
    	return 0;
    }