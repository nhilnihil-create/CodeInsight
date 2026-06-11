#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getmax(ll a, ll b){
	if(a > b)
		return a;
	return b;
}

int main()
{
	ll A, B, K;

	cin >> A >> B >> K;

	ll Takahashi = getmax(0, A - K);
	K  = getmax(0, K - A);
	ll Aoki = getmax(0, B - K);
	cout << Takahashi << ' ' << Aoki << '\n';

	return 0;
}