#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define bitcnt(v) __builtin_popcount(v)
#define all(v) v.begin(), v.end()

void solution(){
	int n; cin >> n;
	int d[n][2];
	bool possible = false;
	int cnt = 0;
	for(int i = 0 ; i < n ; i++){
		cin >> d[i][0] >> d[i][1];
		if(d[i][0] == d[i][1]){
			cnt++;
		}
		else cnt = 0;
		if(cnt >= 3){
			possible |= true;
		}
	}
	cout << (possible ? "Yes" : "No") << endl;


	

}	


int main(){ 
	fio;
	int t;
	t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solution();
	} 
	return 0;
}