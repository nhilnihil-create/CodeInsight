#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
#include<bits/stdc++.h>
using namespace std;
#define y1 y11
#define fi first
#define se second
#define pi acos(-1.0)
#define LL long long
//#define mp make_pair
#define pb emplace_back
#define ls rt<<1, l, m
#define rs rt<<1|1, m+1, r
#define ULL unsigned LL
#define pll pair<LL, LL>
#define pli pair<LL, int>
#define pii pair<int, int>
#define piii pair<pii, int>
#define pdd pair<double, double>
#define mem(a, b) memset(a, b, sizeof(a))
#define debug(x) cerr << #x << " = " << x << "\n";
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//head

int n;
vector<pii> vc;
vector<int> vc1;
int main() {
    scanf("%d", &n);
    if(__builtin_popcount(n) == 1) return 0*puts("No");
    vc.pb(n+1, n+2);
    vc.pb(n+2, n+3);
    vc.pb(n+3, 1);
    vc1.pb(n+3);
    vc.pb(1, 2);
    vc1.pb(2);
    vc.pb(2, 3);
    for (int i = 4; i < n; i += 2) {
        vc.pb(1, i);
        vc1.pb(i);
        vc.pb(i, i+1);

        vc.pb(1, n+i+1);
        vc1.pb(n+i+1);
        vc.pb(n+i+1, n+i);
    }
    sort(vc1.begin(), vc1.end());
    if(n%2 == 0) {
        for (int i = 2; i < n; ++i) {
            if((n^1^i) < n && 1 < (n^1^i)) {
                int x = i;
                int y = n^1^i;
                if(lower_bound(vc1.begin(), vc1.end(), x) != vc1.end() && *lower_bound(vc1.begin(), vc1.end(), x) == x) vc.pb(x, n);
                else vc.pb(n+x, n);
                if(lower_bound(vc1.begin(), vc1.end(), y) != vc1.end() && *lower_bound(vc1.begin(), vc1.end(), y) == y) vc.pb(y, n+n);
                else vc.pb(n+y, n+n);
                break;
            }
        }
    }
    puts("Yes");
    for (auto it : vc) printf("%d %d\n", get<0>(it), get<1>(it));
    return 0;
}
