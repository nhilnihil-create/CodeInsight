#include <bits/stdc++.h>

using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define dump(x) cerr << "~ " << #x << " = " << x << endl

#define eps 1e-14

int main() {

	fast_cin;
	
	long double a,b,c;

	cin >> a >> b >> c;

	a = sqrt(a);
	b = sqrt(b);
	c = sqrt(c);

	if(a+b+eps < c) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	
	return 0;
}