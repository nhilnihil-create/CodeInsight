#include<bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int q; cin >> q;
	string r = "", l = "";
	bool rev = false;
	for (int i = 0; i < q; i++)
	{
		int t; cin >> t;
		if(t == 1) rev = !rev;
		else{
			int f; char c;
			cin >> f >> c;
			if(f == 1) {
				if(!rev) r = c + r;
				else l = l + c;
			}
			else {
				if(!rev) l = l + c;
				else r = c + r;
			}
		}
	}

	if(!rev) cout << r + s + l << endl;
	else {
		string res = r + s + l;
		reverse(res.begin(), res.end());
		cout << res << endl;
	}
	return 0;
}
