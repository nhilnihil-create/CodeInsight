#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	int Q;
	cin >> S >> Q;
	int p = 1;
	vector<char> f, b;
	rep(i,Q) {
		int T;
		cin >> T;
		if (T == 1) {
			p *= -1;
		}
		else {
			int F;
			char C;
			cin >> F >> C;
			if ( F == 1) {
				if (p == 1)	f.push_back(C); 
				else b.push_back(C);
			}
			else {
				if (p == 1) b.push_back(C);
				else f.push_back(C);
			}
		}
	}
	if (p == 1) {
		for (int i = f.size()-1; i >= 0; i--) cout << f[i];
		cout << S;
		for (int i = 0; i < b.size(); i++) cout << b[i];
		cout << endl;
	}
	else {
		for (int i = b.size()-1; i >= 0; i--) cout << b[i];
		reverse(S.begin(), S.end());
		cout << S;
		for (int i = 0; i < f.size(); i++) cout << f[i];
		cout << endl;
	}


	return 0;
}
