#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> w(n);
	rep(i,n) cin >> w[i];
	int s1 = 0;
	int s2 = 0;
	rep(i,n) s2 += w[i];
	int mn = 100000000;
	rep(i,n){
		s1 += w[i];
		s2 = s2 - w[i];
		mn = min(abs(s2-s1),mn);
	}
	cout << mn << endl;
}

// cout << fixed << setprecision(15) <<  << endl;