#include<bits/stdc++.h>
 
using namespace std;

#define int long long

signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
//	int t;
//	cin >> t;
//	while(t--){
		int l,r,k;
		cin >> l >> r >> k;
		if(l%k==0){
			cout << r/k-l/k+1 << endl;
		}
		else{
			cout << r/k-l/k << endl;
		}
//	}
}
