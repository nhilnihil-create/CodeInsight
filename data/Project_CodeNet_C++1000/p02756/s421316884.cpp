#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	string s;
	cin >> s;
	int q;
	cin >> q;

	int count = 0;
	string t = "";
	string u = "";


	for (int i = 0; i < q; i++) {
		int f;
		cin >> f;

		if (f == 1) {
			count++;
		}

		else {
			int a;
			string b;
			cin >> a >> b;

			if (a == 1) {
				if (count %2==0) {
					t += b;
				}
				else {
					u += b;
				}
			}
			else {
				if (count % 2 == 0) {
					u += b;
				}
				else {
					t += b;
				}
			}
		}

	}


	reverse(t.begin(),t.end());
	string k = t + s + u;

	if (count % 2 == 1) {
		reverse(k.begin(), k.end());
	}

	cout << k << endl;
	return 0;
}
