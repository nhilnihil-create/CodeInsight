#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; cin >> N; 
	int A[100010] = {};
	multiset<int> S;  
	S.insert(0); 
	S.insert(0); 
	S.insert(N+1); 
	S.insert(N+1); 
	for(int i = 1; i <= N; i++){
		int a; cin >> a; 
		A[a] = i; 
	}
	long long ans = 0; 
	for(int i = N; i >= 1; i--){
		auto it = S.lower_bound(A[i]); 
		int a2 = *it; 
		it ++; 
		int a1 = *it; 
		it --; it --; 
		int a3 = *it; 
		it --;
		int a4 = *it; 
		ans += (long long) i * (A[i] - a3) * (a1 - a2); 
		ans += (long long) i * (a2 - A[i]) * (a3 - a4); 
		S.insert(A[i]);
	}
	cout << ans << endl; 
}