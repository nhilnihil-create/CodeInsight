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
#define pb push_back
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

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
char s[N];
int n;
bool isl[N];
int main() {
	scanf("%d", &n);
	scanf("%s", s+1);
	isl[1] = 1;
	for (int i = 2; i <= 2*n; ++i) {
		if(s[i] != s[i-1]) isl[i] = (isl[i-1]==true);
		else isl[i] = (isl[i-1]!=true);
	} 
	LL ans = 1, a = 0, b = 0;
	for (int i = 1; i <= 2*n; ++i) {
		if(!isl[i]) {
			if(a-b <= 0) {
				ans = 0;
				break;
			}
			ans = (ans * (a-b))%MOD;
			b++;
		}
		else a++;
	}
	if(a != b) ans = 0;
	if(s[1] == 'W' || s[2*n] == 'W') ans = 0;
	for (int i = 1; i <= n; ++i) ans = (ans*i) % MOD;
	printf("%lld\n", ans);
	return 0;
} 