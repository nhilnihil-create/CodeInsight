/*
	problem: 
	
	
*/

#include<bits/stdc++.h>
/*
#pragma GCC optamize("O2")
#pragma G++ optamize("O2")
*/
using namespace std;
const long long maxn = 0x3f3f3f3f;
typedef long long LL;

LL N, K, C;
// string s;
LL ans[200100];
char s[200100];

int main() {
	
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	
	LL i, j, k;
    scanf("%lld%lld%lld", &N, &K, &C);
    scanf("%s", s);
    LL cnt = 0;
    for (i = 0; i < N; ++ i) {
        if (s[i] == 'o') {
            if (cnt < K) ++ ans[i];
            ++ cnt;
            i = i + C;
        }
    }
    if (cnt > K) return 0;
    LL cnt1 = 0;
    for (i = N - 1; i >= 0; -- i) {
        if (s[i] == 'o' && cnt1 < K) {
            ++ cnt1;
            ++ ans[i];
            i = i - C;
        }
        if (cnt1 >= K) break;
    }
    for (i = 0; i < N; ++ i) {
        if (ans[i] > 1) printf("%lld\n", i + 1);
    }
	
	return 0;
}
/*
11 3 2
ooxxxoxxxoo
5 2 3
ooxoo
16 4 3
ooxxoxoxxxoxoxxo
5 4 0
ooooo
*/ 
