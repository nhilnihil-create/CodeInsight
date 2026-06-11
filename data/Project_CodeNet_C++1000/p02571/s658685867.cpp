#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

string s, t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> t;
	int mindif = 1e9;
	for (int i = 0; i < s.size() - t.size() + 1; i++)
	{
		string ssub(s.begin() + i, s.begin() + i + t.size());
		cerr << ssub << '\n';
		int dif = 0;
		for (int k = 0; k < ssub.size(); k++)
		{
			if (ssub[k] != t[k])
				dif++;
		}
		mindif = min(mindif, dif);
	}
	cout << mindif << '\n';
}