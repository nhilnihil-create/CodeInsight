#include <bits/stdc++.h>
using namespace std;
const int maxn = 200200;
int a[maxn], b[maxn];
int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	priority_queue<pair<int,int> > pq;
	for(int i = 0; i < n; i++) if(b[i] > a[i]) pq.push({b[i], i});
	long long ops = 0;
	while(!pq.empty()){
		int tp = pq.top().second; pq.pop();
		int pv = (tp + n - 1) % n;
		int nx = (tp + 1) % n;
		if(b[tp] > b[pv] + b[nx]){
			int upto = (b[tp] - a[tp]) / (b[pv] + b[nx]);
			if(upto == 0){
				cout << -1 << endl;
				return 0;
			}
			ops += upto;
			b[tp] -= upto * (b[pv] + b[nx]);
			if(b[tp] > a[tp]) pq.push({b[tp], tp});
		} else {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ops << endl;
	return 0;
}
