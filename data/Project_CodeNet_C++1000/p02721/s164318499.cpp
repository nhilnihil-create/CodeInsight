#include<iostream>
#include <algorithm>
#include<queue>
using namespace std;


char s[200005];
int n, k, c;
int main() 
{
	cin >> n >> k >> c >> s;
	vector<int> l, r;
	int temp = 0x3f3f3f3f;
	for (int i = 0; i < n; i++)
	{
		if (l.size() == k)
			break;
		if (s[i] == 'o' && temp >= c)
		{
			l.push_back(i);
			temp = 0;
		}
		else
			temp++;
	}
	temp = 0x3f3f3f3f;
	for (int i = n - 1; i >= 0; i--)
	{
		if (r.size() == k)
			break;
		if (s[i] == 'o' && temp >= c)
		{
			r.push_back(i);
			temp = 0;
		}
		else
			temp++;
	}
  	reverse(r.begin(),r.end());
	for (int i = 0; i < k; i++)
	{
		if (l[i] == r[i])
			cout << l[i]+1 << endl;
	}
	return 0;
}
