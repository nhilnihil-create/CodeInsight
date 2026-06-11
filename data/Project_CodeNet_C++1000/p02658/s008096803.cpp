#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int N; cin >> N;
	vector<ll> A(N);
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
	
	ll ans = 1;
	sort(A.begin(),A.end());
	if(A[0] == 0){cout << 0 << endl; return 0;}
	for(int i=0; i<N; i++){
		if(A[i] <= 1000000000000000000LL/ans){
			ans *= A[i]; 
		} else {
			cout << -1 << endl; return 0;
		}
	}
	cout << ans << endl;

	return 0;

}
