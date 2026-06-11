#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a;
		cin >> a;
		n -= a;
	}
	if(n<0) cout << -1;
	else cout << n;
	return 0;
}
