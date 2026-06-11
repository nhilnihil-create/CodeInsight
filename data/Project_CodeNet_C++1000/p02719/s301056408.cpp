#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<string>
#include<iostream>
#define R(i, n) for(int i = 0; i < n; i++)
#define S(a) scanf("%d", &a)
#define S2(a, b) scanf("%d%d", &a, &b)
#define S3(a, b, c) scanf("%d%d%d",  &a, &b, &c)
#define SL(a) scanf("%lld", &a)
#define P(a) printf("%d", a)
#define PL(a) printf("%lld", a);
#define PY printf("%s", "Yes");
#define PN printf("%s", "No");
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int, int> IR;

int main(){
	ll n, k;
	SL(n);
	SL(k);
	ll mod = n % k;
	ll diff = k - mod;
	PL(min(mod, diff));
}