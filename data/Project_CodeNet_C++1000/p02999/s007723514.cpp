#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll x, a;
	scanf("%lld %lld", &x, &a);
	puts(x < a ? "0" : "10");
	return 0;
}