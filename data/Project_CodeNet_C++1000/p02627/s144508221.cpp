#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define rep(n) for(int i = 0;i<n;i++)
#define all(v) v.begin(),v.end()
#define print(v) for(auto n:v){cout << n << "\t";}
#define quick                    \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using namespace std;
void solve(){
	char c;
	cin >> c;
	// cout << c;
	if(c>='a' && c<='z'){
		cout << 'a' ;
	}
	else{
		cout << 'A';
	}
	cout << endl;
	

}


int main(){
	// int t;
	// cin >> t;
	solve();
	// while(t--){
	// 	solve();
	// }

	return 0;
}