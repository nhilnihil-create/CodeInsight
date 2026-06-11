#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n, x;
	cin >> n >> x;
	
	int cnt = 1;
	int d = 0;
	rep(i, n){
		int l;
		cin >> l;
		d += l;
		if(d <= x) cnt++;
	}

	cout << cnt << endl;

	return 0;
}
