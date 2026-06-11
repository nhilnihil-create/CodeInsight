#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;
int n;

int solve(vector<int> a){
	int ret = 0;
	rep(i, n){
		int c;
		c = ((n - 1) & i) == i ? 1 : 0;
		ret += c * a[i];
		ret %= 2;
	}

	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);


	cin >> n;

	string s;
	cin >> s;

	bool have_one = false;
	vector<int> a(n);
	rep(i, n) {
		a[i] = s[i] - '1';
		if(a[i] == 1) have_one = true;
	}

	if(have_one){
		rep(i, n){
			if(a[i] == 2) a[i] = 0;
		}
	}else{
		rep(i, n){
			if(a[i] == 2) a[i] = 1;
		}
	}

	int ans = solve(a);
	if(!have_one) ans *= 2;
	
	cout << ans << endl;
}
