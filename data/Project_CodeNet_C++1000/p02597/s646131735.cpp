#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long int li;
typedef long long ll;
typedef long double ld;

int main()
{
	FastIO;
	int n, k = 0;
	string s;
	cin >> n >> s;
	vector<int> w;
	vector<int> r;
	for (int i = 0; i < n; i++)
		if (s[i] == 'W')
			w.push_back(i);
		else
			r.push_back(i);
	sort(w.begin(), w.end());
	sort(r.rbegin(), r.rend());
	if (w.size())
	{
		if (w.size() >= r.size())
		{
			for (int i = 0; i < r.size(); i++)
				if (w[i] < r[i])
					k++;
		}
		else
		{
			for (int i = 0; i < w.size(); i++)
				if (w[i] < r[i])
					k++;
		}
		cout << k << "\n";
	}
	else
		cout << "0\n";
}
