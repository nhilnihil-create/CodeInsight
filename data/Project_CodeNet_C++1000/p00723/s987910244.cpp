#include <bits/stdc++.h>
using namespace std;
int m;
string s, a, b, c, d;
typedef unordered_set<string> set_t;
int main()
{
	cin >> m;
	for(int i=0; i<m; i++)
	{
		cin >> s;
		set_t A{};
		for(int k=1; k<s.size(); k++)
		{
			a=s.substr(0, k);
			b=s.substr(k);
			c=a;
			d=b;
			reverse(c.begin(), c.end());
			reverse(d.begin(), d.end());
			A.insert(a+b);
			A.insert(b+a);
			A.insert(a+d);
			A.insert(d+a);
			A.insert(c+b);
			A.insert(b+c);
			A.insert(c+d);
			A.insert(d+c);
		}
		cout << A.size() << endl;
	}
	return 0;
}