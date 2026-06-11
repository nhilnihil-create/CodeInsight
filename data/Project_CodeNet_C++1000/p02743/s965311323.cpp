#include <bits/stdc++.h>

using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define dump(x) cerr << "~ " << #x << " = " << x << endl

#define eps 1e-14

int main() {

	fast_cin;
	
	long long a,b,c,lf,ri;

	cin >> a >> b >> c;

	lf = (a * b * 4LL);
	ri = (c-a-b) * (c-a-b);

	if(c-a-b < 0) {
		cout << "No" << endl;
	} else if(lf < ri) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	
	
	return 0;
}