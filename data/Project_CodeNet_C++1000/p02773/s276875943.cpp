#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define dd pair<double, double>
#define pb(i) push_back(i)
const double PI = 3.14159265359;
const int inf = 1e9+77;
const ll mod = 1e9+7;
const double eps = 1e-7;
//int dir1[8] = {0, 0, 1, -1, 1, -1, 1, -1};
//int dir2[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dir1[4] = {0, 0, 1, -1};
int dir2[4] = {1, -1, 0, 0};

ll inv_mod(ll a);

#define si pair<string, int>
#define is pair<int, string>

bool by(is a, is b)
{
	if(a.first < b.first)
		return false;
	else if(a.first > b.first)
		return true;
	else
	{
		if(a.second.compare(b.second) < 0)
			return true;
		else
			return false;
	}
}

int main()
{
	int i, j;

	vector<pair<int, string> > v;
	map<string, int> p;
	int n;
	string s;
	cin >> n;

	while(n--)
	{
		cin >> s;
		if(p.find(s) == p.end())
		{
			p.insert(si(s, (int)p.size()));
			v.pb(is(1, s));
		}
		else
		{
			int ind = p.find(s)->second;
			v[ind].first++;
		}
	}

	sort(v.begin(), v.end(), by);

	cout << v[0].second << '\n';
	for(i = 1; i < v.size(); i++)
	{
		if(v[i].first == v[i-1].first)
			cout << v[i].second << '\n';
		else
			break;
	}
}


ll inv_mod(ll a)
{
	ll b = mod-2, ans = 1;
	while(b)
	{
		if(b&1)
			ans = (ans*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return ans;
}