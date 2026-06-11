#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n;
string s;

bool check(int len)
{
	map<string, int> h;
	for (int i = 0; i <= n - len + 1; i ++ )
	{
		string t = s.substr(i, len);
		if (h.count(t))
		{
			if (h[t] + len <= i) return true;
		}
		else h[t] = i;
	}
	return false;
}

int main()
{
	cin >> n >> s;
	
	int l = 0, r = n;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << r << endl;
    return 0;
}