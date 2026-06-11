#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) REP(i, 0, (n))
#define REP(i, a, n) for(int i=(a); i<(n); i++)

int main(){
	int N;
	int f[200];
	static int dp1[1000000], dp2[1000000];
	rep(i, 200) f[i] = i*(i+1)*(i+2)/6;
	dp1[0] = dp2[0] = 0;
	REP(i, 1, 1000000){
		dp1[i] = dp2[i] = i;
		for(int j=0; f[j]<=i; j++){
			dp1[i] = min(dp1[i], dp1[i-f[j]]+1);
			if(f[j]%2==1) dp2[i] = min(dp2[i], dp2[i-f[j]]+1);
		}
	}
	while(cin >> N, N)
		cout << dp1[N] << " " << dp2[N] << endl;
}

