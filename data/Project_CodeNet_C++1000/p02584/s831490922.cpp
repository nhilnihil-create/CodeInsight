#include <bits/stdc++.h>
using namespace std;
long long x,k,d;
int main() {
	cin>>x>>k>>d;
	if(x<0) {
		x*=-1;
	}
	if(x/d>k) {
		cout<<x-k*d;
	}
	else {
		long long y;
		while(x>=0) {
			y=x;
			x-=d;
			k--;
		}
		if (k%2==0) {
			cout<<abs(x)<<endl;
		} else {
			cout<<abs(y)<<endl;
		}
	}
	return 0;
}
