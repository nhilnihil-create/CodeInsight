#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> score(n);

	rep(i, q){
		int d;
		cin >> d;
		score.at(d-1)++;
	}

	vector<bool> ans(n);
	rep(i, n){
		int genten = q - score.at(i);
		if(k - genten > 0) ans.at(i) = true;
	}

	rep(i, n){
		if(ans.at(i)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
