#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <cstdlib>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 2e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;


int A[N], B[N], n;
int q[60 * N], cur, sz;

inline int prv(int x){
	return (x - 1 + n) % n;
}

inline int nxt(int x){
	return (x + 1) % n;
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", A + i);
	for(int i = 0;i < n;i++)
		scanf("%d", B + i);
	for(int i = 0;i < n;i++){
		if(B[i] > B[prv(i)] + B[nxt(i)] && B[i] > A[i])
			q[sz++] = i;
	}
	ll sol = 0;
	for(;cur < sz;){
		int i = q[cur++];
		int potez = (ll)(B[i] - A[i] + B[prv(i)] + B[nxt(i)] - 1) / (B[prv(i)] + B[nxt(i)]);
		if(B[i] <= potez * (B[prv(i)] + B[nxt(i)]))
			potez--;
		sol += potez;
		B[i] = B[i] - potez * (B[prv(i)] + B[nxt(i)]);
		if(B[prv(i)] > A[prv(i)] && B[prv(i)] > B[prv(prv(i))] + B[i])
			q[sz++] = prv(i);
		if(B[nxt(i)] > A[nxt(i)] && B[nxt(i)] > B[nxt(nxt(i))] + B[i])
			q[sz++] = nxt(i);
		if(B[i] > A[i] && B[i] > B[prv(i)] + B[nxt(i)])
			q[sz++] = i;
	}
	bool ans = 1;
	for(int i = 0;i < n;i++)
		ans &= (A[i] == B[i]);
	printf("%lld\n", ans ? sol : -1);
	return 0;
}