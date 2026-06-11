#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
	
	int n; cin >> n;
	string s; cin >> s;
	int ans = 0;

	int l = 0;
	int r = n - 1;

	while(l < r){
		bool flag = 1;
		if(s[l] != 'W'){
			flag = 0;
			l++;
		}
		if(s[r] != 'R'){
			flag = 0;
			r--;
		}
		if(flag == 1){
			ans++;
			l++;
			r--;
		}

	}

	
	
	cout << ans << endl;
	
	return 0;
}
