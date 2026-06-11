#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) FOR(i, 0, (n))
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#ifdef LOCAL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define N 512
int a[N][N]={};

int main(){
	int n; scanf("%d", &n);
	REP(i, 9){
		REP(j, N){
			REP(k, N){
				if(a[j][k]) continue;
				if((j&(1<<i)) != (k&(1<<i))) a[j][k]=i+1;
			}
		}
	}
	REP(i, n){
		FOR(j, i+1, n){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
