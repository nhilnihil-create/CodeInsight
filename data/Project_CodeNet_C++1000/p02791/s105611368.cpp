#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
typedef long long ll;

using namespace std;

int main(){

	int n;
	cin >> n;
	int p[200000]={0};
	int ans=0;
	REP(i,n){
		cin >> p[i];
	}
	int m = p[0];
	REP(i,n){
		m = min(m,p[i]);
		if(m == p[i])ans++;
	}
	cout << ans << endl;

    return 0;
}