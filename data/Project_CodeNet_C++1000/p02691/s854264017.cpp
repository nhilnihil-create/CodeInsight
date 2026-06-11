#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	LL a[n];
	map<LL,LL> l,r;
	LL ans = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		ans += r[i+a[i]];
		ans += l[i-a[i]];
		l[i+a[i]]++;
		r[i-a[i]]++;
	}
	// syutsuryoku
	cout << ans << endl;
}