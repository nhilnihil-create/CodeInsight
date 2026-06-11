#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define LL long long

int main(){
	// sengen
	int n,m;
	// nyuryoku
	cin >> n >> m;
	int ans = n-1;
	dsu d(n);
	int a[m],b[m];
	for(int i=0;i<m;i++){
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		if(!d.same(a[i],b[i])){
			d.merge(a[i],b[i]);
			ans--;
		}
	}
	// keisan
	cout << ans << endl;
	// syutsuryoku
}