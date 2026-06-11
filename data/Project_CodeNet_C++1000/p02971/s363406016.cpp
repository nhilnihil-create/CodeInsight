#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	vector<int> b = a;
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	rep(i,n){
		if(a[i] == b[0]) cout << b[1] << endl;
		else cout << b[0] << endl;
	}
}

// cout << fixed << setprecision(15) <<  << endl;