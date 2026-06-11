#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	lli x = 0;
	vector<lli> a(n);
	rep(i, n) cin >> a[i];
	lli l = 0, r = n-1;
	while(l <= r){
		if(x <= 0){
			x += a[l];
			l++;
		}else{
			x -= a[r];
			r--;
		}
	}
	cout << abs(x) << endl;
	return 0;
}
