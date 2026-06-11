#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	priority_queue<long long> que;
	long long n,m;
	// nyuryoku
	cin >> n >> m;
	LL a[n];
	for(LL i=0;i<n;i++){
		cin >> a[i];
		que.push(a[i]);
	}
	// keisan
	for(LL i=0;i<m;i++){
		LL b = que.top();
		que.pop();
		que.push(b/2);
	}
	LL ans = 0;
	for(LL i=0;i<n;i++){
		ans += que.top();
		que.pop();
	}
	// syutsuryoku
	cout << ans << endl;
}