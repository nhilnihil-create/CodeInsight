#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i,n){
		cin >> p[i];
	}
	int ans = 0;
	int minimum = p[0];
	rep(i,n){
		if(p[i] <= minimum) {
			ans++;
			minimum = p[i];
		}
	}
	cout << ans << endl;
}