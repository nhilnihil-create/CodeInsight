#include <bits/stdc++.h>
using namespace std;
bool pt(int n) {
	return (n&(-n)) == n;
}
void eg(int a, int b) {
	cout << a << " " << b << '\n';
}
int lso(int n) {
	return n&(-n);
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	if(pt(n)) {
		cout << "No\n";return 0;
	}
	if(n%4 != 3 && n <= 4) {
		cout << "No\n";return 0;
	}
	cout << "Yes\n";
	for(int i=0;i<2;i++) {
		eg(i+1,i+2);
	}
	eg(3,n+1);
	for(int i=0;i<2;i++) {
		eg(n+i+1,n+i+2);
	}
	for(int i=4;i<n;i+=2) {
		eg(i,i+1);
		eg(i+1,1);
		eg(1,i+n);
		eg(i+n,i+n+1);
	}
	if(n%2 == 0) {
		int a = lso(n),b = (n-lso(n))+1;
		eg(n,a+n);
		eg(b,n+n);
	}
}
