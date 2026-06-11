#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vector<array<int, 4>> request;
int mx = 0;

int scoreSeq(vi v)
{
	reverse(v.begin(), v.end());
	int ans = 0;
	for(auto req: request )
		if(v[req[1]] - v[req[0]] == req[2])
			ans += req[3];
	return ans;
}


void solve(int n, int m, vi &vec)
{
	if(n == 0)
		mx = max(mx, scoreSeq(vec));
	else
	{
		per(i, m, 1)
		{
			vec.push_back(i);
			solve(n-1, i, vec);
			vec.pop_back();
		}

	}
}

int main(int argc, char const *argv[])
{
	//ifstream cin("input.txt");
	int n,m,q;
	cin>>n>>m>>q;
	rep(i, 0, q - 1)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--;
		b--;
		request.push_back({a,b,c,d});
	}
	vi vec = {};
	solve(n, m, vec);
	cout<<mx;


}