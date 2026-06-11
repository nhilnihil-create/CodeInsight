#include <bits/stdc++.h>
using namespace std;
int N, Q;
long long B[500010]; 
void add(int idx, long long s){
	int x = idx; 
	while(x <= N){
		B[x] += s; x += x & -x; 
	}
}
long long sum(int idx){
	long long res = 0; 
	int x = idx; 
	while(x > 0){
		res += B[x]; x -= x & -x;
	}
	return res; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q; 
	for(int i = 1; i <= N; i++){
		long long a; cin >> a; 
		add(i, a); 
	}
	while(Q--){
		int a; cin >> a; 
		if(a == 0){
			int p; long long x; cin >> p >> x; 
			add(p + 1, x); 
		}else if(a == 1){
			int l, r; cin >> l >> r; 
			cout << sum(r) - sum(l) << "\n"; 
		}
	}
}