#include <bits/stdc++.h>
using namespace std;

int A[200005];
int B[200005];

typedef pair<int, int> pii;
typedef long long LL;
int main(){
	int N; cin >> N;
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}
	for (int i = 0; i < N; i++){
		cin >> B[i];
	}

	priority_queue<pii> pq;
	LL res = 0;
	for (int i = 0; i < N; i++){
		if (A[i] != B[i]){
			pq.push(make_pair(B[i], i));
		}
	}
	while (pq.size()){
		pii p = pq.top(); pq.pop();
		//cout << p.first << ' ' << p.second << endl;
		int idx = p.second;
		int rgt = (idx + 1) % N;
		int lft = (idx + N - 1) % N;
		int dec = (B[idx] - A[idx])  / (B[rgt] + B[lft]);
		if (dec == 0){
			cout << -1 << endl;
			return 0;
		}
		p.first -= dec * (B[rgt] + B[lft]);
		res += dec;
		B[p.second] = p.first;
		if (p.first == A[idx]) continue;
		if (p.first < A[idx]){
			cout << -1 << endl;
			return 0;
		}
		pq.push(p);
	}
	cout << res << endl;
}
