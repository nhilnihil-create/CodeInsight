#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int k, x;
	cin >> k >> x;

	rep(i, k*2-1){
		if(i != k*2-2) cout << x-k+1+i << " ";
		else cout << x-k+1+i << endl;
	}

	return 0;
}