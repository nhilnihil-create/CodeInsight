#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define rep(n) for(int i = 0;i<n;i++)
#define all(v) v.begin(),v.end()
#define print(v) for(auto n:v){cout << n << "\t";}
#define quick                    \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using namespace std;
void solve(){
	int n;
	cin >> n;
	vll v(n);
	ll allxor = 0;
	for(auto &i:v){
		cin >> i;
		allxor = allxor ^i;
	}
	rep(n){
		ll t = allxor^v[i];
		cout <<  t << " ";
	}
	cout << endl;
	


	

}


int main(){
	solve();
	// int t;
	// cin >> t;
	// while(t--){
	// 	solve();
	// }

	return 0;
}