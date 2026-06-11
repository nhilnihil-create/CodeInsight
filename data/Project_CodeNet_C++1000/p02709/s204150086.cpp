#include <iostream>
#include<map>
#include<algorithm>
#include<cstring>
#include<cmath>

#define LL	long long
using namespace std;
const int MAXN = 2010;
const int MAXA = 1e9;

pair<int, int> A[MAXN];
LL f[MAXN][MAXN];
int N;
LL ans;

int main() {
	cin >> N;
	memset(f, 0, sizeof(f));
	for(int i=1; i<=N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	
	sort(A+1, A+N+1);
	//sort(A+1, A+N+1, greater<int>());
	
	/*
	for(int i=1; i<=N; i++) {
		printf("%d, %d\n", A[i].first, A[i].second);
	}
	*/
	for(int len = N; len>=1; len--) {
		for(int i=1; i+len-1<=N; i++) {
			int j = i+len-1;
			if(len == 1) {
				ans = max(ans, f[i][i] + 1LL*A[len].first*abs(A[len].second-i));
			}
			f[i+1][j] = max(f[i+1][j], f[i][j] + 1LL*A[len].first*abs(A[len].second-i));
			f[i][j-1] = max(f[i][j-1], f[i][j] + 1LL*A[len].first*abs(A[len].second-j));
		}
	}
	cout<<ans<<endl;
	return 0;
}