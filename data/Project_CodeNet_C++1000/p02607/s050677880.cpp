#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
int n, x, m=0;
set<int>s;
vector<pair<int,int>>v;
int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (x % 2 == 1 && i % 2 == 1)
			m++;

	}
	cout << m;
}