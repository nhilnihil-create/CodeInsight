// orz dxm
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define y0 yORZDXM
#define y1 yORZDXM
#define y2 yORZDXM
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;

int n;

int main(){
	scanf("%d", &n);
	REP(i, 1, n) REP(j, i + 1, n){
		int k = i ^ j, ans;
		for(ans = 0; !(k >> ans & 1); ++ans);
		printf("%d%c", ans + 1, j == n ? '\n' : ' ');
	}
	return 0;
}

