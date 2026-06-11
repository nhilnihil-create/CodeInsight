#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

Int n, ans;
vector<Int> a, b;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	a.resize(n);
	b.resize(n);
	for(auto &i:a) cin >> i;
	for(auto &i:b) cin >> i;
	using P = pair<Int, Int>;
	priority_queue<P> pq;
	for(size_t i=0; i<a.size(); ++i)
		if(b[i] > a[i])
			pq.push(P(b[i], i));
	while(!pq.empty()){
		P p = pq.top();
		pq.pop();
		Int d = b[(p.second-1+n)%n] + b[(p.second+1)%n];
		Int t = (b[p.second] - 1) / d;
		t = min(t, (b[p.second] - a[p.second]) / d);
		b[p.second] -= t * d;
		ans += t;
//		for(size_t i=0; i<b.size(); ++i)
//			cout << b[i] << " \n"[i+1==b.size()];
		if(t == 0){
			ans = -1;
			break;
		}else if(b[p.second] > a[p.second]){
			pq.push(P(b[p.second], p.second));
		}
	}
	cout << ans << "\n";
}