#include<bits/stdc++.h>
#define mod7 1000000007

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c, k, ct=0;
	cin>>a>>b>>c>>k;
	while(a>=b) {
		b *= 2;
		ct++;
	}
	while(b>=c) {
		c *= 2;
		ct++;
	}
	if (ct>k) cout<<"No\n";
	else cout<<"Yes\n";
}

