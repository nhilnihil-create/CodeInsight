#include <bits/stdc++.h>

using namespace std;

int sm(int n){
	return n * (n-1) / 2;
}

int main(){
	int n,m; cin >> n >> m;
	cout << sm(n) + sm(m);
	return 0;
}
