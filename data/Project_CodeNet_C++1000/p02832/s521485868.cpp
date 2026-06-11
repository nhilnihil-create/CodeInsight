#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000009
#define pi 2*acos(0)
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
using namespace std;


int main()
{

	io;
	
	int n; cin >> n;
	vi vis(n+1, 0);
	vi v;
	int tar = 1;
	int del = 0;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if (x == tar) {
			vis[tar] = 1;
			tar++;
		}
		else {
			del++;
		}
	}

	if (del == n) cout << -1;
	else cout << del;
}

