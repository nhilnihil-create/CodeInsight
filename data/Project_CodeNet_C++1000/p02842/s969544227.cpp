#include <bits/stdc++.h>

using namespace std;
#define NIL -1
#define ll long long
#define MAX 100
#define pb push_back

int main()
{
	int n;
	cin >> n;
	int x = (int)(double)n/1.08;
	int y = (int)ceil((double)n/1.08);
	if((int)(x*1.08) == n) {
		cout << x << endl;
	}
	else if((int)(y*1.08) == n) cout << y << endl;
	else cout << ":(\n";
	return 0;
}
