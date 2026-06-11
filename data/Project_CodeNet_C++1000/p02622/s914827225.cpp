#include<vector>
#include<queue>
#include<iostream>
#include<set>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
long long n, x, y, m, k, c = 0, l=0;
set<int>s1, s2, s3;
queue<long long>v1, v2;
int main()
{
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != t[i])
			c++;
	}
	cout << c;
}