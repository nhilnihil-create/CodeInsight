#include<bits/stdc++.h>
#define int long long int
using namespace std;

#undef int
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
#define int long long int
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1;
	//cin >> t;
	while (t--) {
		int a,b;
		cin >> a>>b;
		if(b>=a)
			cout<<"unsafe"<<endl;
		else
			cout<<"safe"<<endl;
	}
	return 0;
}