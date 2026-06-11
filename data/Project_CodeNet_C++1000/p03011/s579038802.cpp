#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int p,q,r;
	cin >> p >> q >> r;
	
	if(p <= q){
		cout << p + min(q,r) << endl;
		return 0;
	}
	if(q <= r){
		cout << q + min(r,p) << endl;
		return 0;
	}
	if(r <= p){
		cout << r + min(p,q) << endl;
		return 0;
	}
}