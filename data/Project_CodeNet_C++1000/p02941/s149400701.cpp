#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

int n, m;
int a[202020], b[202020];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];
	
	priority_queue<p> pq;
	for(int i=0; i<n; i++) pq.push({b[i], i});
	
	long long ans = 0;
	while(pq.size()){
		int i = pq.top().second; pq.pop();
		int st =  b[(i+1)%n] + b[(i+n-1)%n];
		
		if((b[i] - a[i]) % st == 0){
			ans += (b[i] - a[i]) / st;
			b[i] = a[i];
			continue;
		}
		if(st >= b[i]){
			cout << -1; return 0;
		}
		
		ans += b[i] / st;
		b[i] %= st;
		if (b[i] < a[i]) {
			cout << -1; return 0;
		}
		pq.push({b[i], i});
	}
	cout << ans;
}