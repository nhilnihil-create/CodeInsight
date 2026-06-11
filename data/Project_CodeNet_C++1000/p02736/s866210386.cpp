#include <bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fi first
#define se second
#define MK make_pair
#define PB push_back
using namespace std;

typedef long long LL;
typedef pair<int ,int> PII;
const int N=1e6+10;

char s[N];
int n;
int solve(){
	int res=0;
	for (int i=0; i<n; ++i){
		// calc bionomial(n,i) % 2 using lucas
		int j=1;
		for (int k=0;(1<<k)<n;++k)
			if ( ((n-1)>>k&1) < (i>>k&1)){
				j=0;break;
			}
		res ^= j*s[i];
	}
	return res;
}
int main(){
	#ifdef che
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	scanf("%d%s", &n,s);
	int cnt[3] = {0,0,0};
	for (int i=0;i<n;++i){
		--s[i];
		++cnt[s[i]-'0'];
	}

	if (cnt[1]==0){
		for (int i=0; i<n; ++i) s[i] = (s[i]>'0');
		printf("%d\n", solve()*2);
	}	else{
		for (int i=0; i<n; ++i) s[i] = (s[i]-'0')%2;
		printf("%d\n", solve());
	}
	return 0;
}