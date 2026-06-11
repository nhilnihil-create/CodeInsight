#include <bits/stdc++.h>
using  namespace std;
int main(int argc, char const *argv[])
{
	int n, m;
	priority_queue<int> pq;
	while(cin >> n >> m){
		while(!pq.empty()) pq.pop();
		for(int i = 0; i < n; i++){
			int temp; cin >> temp;
			pq.push(temp);
		}
		for(int i = 0; i < m; i++){
			int top = pq.top(); pq.pop();
			pq.push(top/2);
		}
		long long ans = 0;
		while(!pq.empty()){
			ans += pq.top(); pq.pop();
		}
		printf("%lld\n", ans);
	}
	return 0;
}