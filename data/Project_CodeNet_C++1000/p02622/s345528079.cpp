						/* In the name of Allah */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string x, t;
	cin >> x >> t;
	int co1 = 0;
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] != t[i])
			co1++;
	}
	cout << co1 << endl;
    return 0;
}