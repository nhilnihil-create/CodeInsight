#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
	ll n, k;
	cin >> n >> k;
	
	int a[n];
	for(int i = 0; i<n; i++) 
	{
		cin >> a[i];
		a[i]--;
	}
	
	set<int> visited;
	visited.insert(0);
	int nx = a[0], turns = 0;
	int t[n], cycle = 1;
	t[0] = 0;
	int e = k;
	
	while(e--)
	{
		if(visited.find(nx) == visited.end())
			visited.insert(nx);
		else
		{
			cycle = turns - t[nx] +1;
			break;
		}
		turns++;
		t[nx] = turns;
		nx = a[nx];
	}
	//for(int x :t) cout << x << endl;
	if(k<=turns)
	{
		nx = a[0];
		k--;
		while(k--)
		{
			nx = a[nx];
		}
		cout << nx+1 << "\n";
	}
	else
	{
		nx = a[0];
		k-=turns; k%=cycle;
		turns--;
		while(turns-->0)
		{
			nx = a[nx];
		}
		while(k-->0)
		{
			nx = a[nx];
		}
		cout << nx+1 << "\n";	
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}

