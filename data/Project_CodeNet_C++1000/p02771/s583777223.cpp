#include <bits/stdc++.h>
using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	set<int> myset;
	myset.insert(A);
	myset.insert(B);
	myset.insert(C);
	if(myset.size() == 2)
		cout << "Yes" << '\n';
	else cout << "No" << '\n';

	return 0;
}