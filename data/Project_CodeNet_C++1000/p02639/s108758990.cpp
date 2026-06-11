#include<bits/stdc++.h>
using namespace std;


int main()
{
	int x[5];
	int c;
	for (int i = 0; i < 5; ++i)
	{
		cin >> x[i];
		if (!x[i]) c = i + 1;
	}
	cout << c << endl;
}

