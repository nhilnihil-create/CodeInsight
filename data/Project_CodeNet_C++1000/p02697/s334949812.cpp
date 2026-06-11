#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#include<cstring>
#include<string>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define SZ(a) (int)((a).size())
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> Pii;
typedef pair <ll, int> Pli;
typedef unsigned long long ull;
const double eps = 1e-8;
const ll infll = 0x7fffffffffffffff;
const int mod = (int)(1e9) + 7;
const int inf = 0x7fffffff;
const int maxn = (int)(2e5) + 7;
const int maxm = 300;

ll N, M;

int main() {
	
	scanf("%lld%lld", &N, &M);
	if (N & 1) {
		for (ll i = 1; i <= M; i++) 
			printf("%lld %lld\n", i, N - i + 1);
	} else {
		ll lim = N / 2 - 1;
		if (lim & 1) lim = lim / 2 + 1;
		else lim /= 2;//能够构造出的个数中奇数个数
		for (ll i = 1; i <= M; i++) 
			printf("%lld %lld\n", i, N - i + 1 - (i > lim));
	}

	return 0;
}		