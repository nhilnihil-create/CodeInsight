#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,k;
	cin >> k >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	vector<int> l(n);
	rep(i,n-1){
		l[i] = a[i+1] - a[i]; 
	}
	l[n-1] = k - a[n-1] + a[0];
	int max = 0;
	rep(i,n){
		if(max < l[i]) max = l[i];
	}
	int sum = 0;
	rep(i,n){
		sum += l[i];
	}
	// rep(i,n) cout << l[i] << endl;
	cout << k-max << endl;
}