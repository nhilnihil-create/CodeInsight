#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
	cin >> n;
	vector<lli> a(n), b(n);
	rep(i, n){
		cin >> a[i];
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	lli ans;
	if(n%2 == 1){
		ans = b[n/2]-a[n/2]+1;
	}else{
		ans = b[n/2-1]+b[n/2]-(a[n/2-1]+a[n/2])+1;
	}
	cout << ans << endl;
	return 0;
}
