#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int  n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	int counts = 0;
	int sa = 0;
	rep(i,n){
		a[i] += sa;
		if(a[i] == i+1) continue;
		else{
			counts++;
			sa++;
		}
	}
	if(counts == n) cout << -1 << endl;
	else cout << counts << endl;
}