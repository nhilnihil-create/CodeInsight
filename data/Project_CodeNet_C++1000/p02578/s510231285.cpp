#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	rep(i, n) cin >> a.at(i);

	ll min_val = a.at(0);
	ll max_val = 0;

	ll flag = 0;

	rep(i,n){
		min_val = max(min_val, a.at(i));

		if(min_val> a.at(i)){
			flag += min_val - a.at(i);
		}
	}

	cout << flag;
}
