#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define debug1(a) cout<<#a<<" "<<(a)<<endl;
#define debug2(a,b) cout<<#a<<" "<<(a)<<" "<<#b<<" "<<(b)<<endl;
#define debug3(a,b,c) cout<<#a<<" "<<(a)<<" "<<#b<<" "<<(b)<<" "#c<<" "<<(c)<<endl;
typedef long double ld;
vector<pair<ld, ld>> v;
ld fact(ld n)
{
	ld res = 1;
	for (int i = 1; i <= n; i++)
	{
		res *= i;
	}
	return res;
}
void swap(pair<ld, ld> &a, pair<ld, ld> &b)
{
	pair<ld, ld> temp;
	temp = a;
	a = b;
	b = temp;
}
ld val = 0;
void permutation(vector<pair<ld, ld>> v, ll start, ll end)
{
	if (start == end)
	{
		for (int i = 1; i < v.size(); i++)
		{
			pair<ld, ld> prev = v[i - 1];
			pair<ld, ld> now = v[i];
			val += sqrt(pow((abs(prev.first - now.first)), 2) + (pow((abs(prev.second - now.second)), 2)));
		}

		return;
	}
	int i;
	for (i = start; i <= end; i++)
	{
		//swapping numbers
		swap(v[i], v[start]);
		//fixing one first digit
		//and calling permutation on
		//the rest of the digits
		permutation(v, start + 1, end);
		swap(v[i], v[start]);
	}
}
void solve()
{
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ld x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	permutation(v, 0, n - 1);
	ld res = val / fact(n);
	cout << fixed << setprecision(10) << res << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}
}