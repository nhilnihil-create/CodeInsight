#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int A,B,C;

	cin >> A >> B >> C;

	C-=abs(A-B);
	C = max(C,0);

	cout << C << '\n';
	
	return 0;
}
