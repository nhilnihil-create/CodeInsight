#include<bits/stdc++.h>
#define SPEED ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long int
#define inf 999999999
#define maxn 200003
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7;
using namespace std;
void code()
{
	ll x, k, d;
	cin >> x >> k >> d;
	x = abs(x);
	ll rmoves = min(k, x/d);
	k-=rmoves;
	x-=rmoves*d;
	if(k%2==0)
	{
		cout << x;
	}
	else
	{
		cout << d-x;
	}
}
int main()
{
	SPEED
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.out","w",stdout);
	#endif
	int t = 1;
	while(t--)
	{
		code();//DEBUG
	}
}