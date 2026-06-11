#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;

int n,m,q;
vector<int> a,b,c,d;

int dfs(int depth, vector<int> &A){
	if(depth==n){
		int ans=0;
		REP(i,q){
			if(A[b[i]-1] - A[a[i]-1] == c[i]) ans += d[i];
		}
		return ans;
	}
	
	int ans=0;
	if(depth==0){
		for(int i=1; i<=m; i++){
			A[depth] = i;
			ans = max(ans, dfs(depth+1, A));
		}
		return ans;
	}else{
		for(int i=A[depth-1]; i<=m; i++){
			A[depth] = i;
			ans = max(ans, dfs(depth+1, A));
		}
		return ans;
	}
	
	
	
}

int main(){
	cin >> n >> m >> q;
	a.resize(q);
	b.resize(q);
	c.resize(q);
	d.resize(q);
	REP(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i];
	
	vector<int> A(n);
	int ans = dfs(0,A);
	
	cout << ans << endl;
	
	return 0;
}