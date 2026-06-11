 #include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	ll s; cin >> s;
	const ll _1e9 = 1000000000;
	cout << 0 << " " << 0 << " " << _1e9 << " " << (s % _1e9 == 0 ? 0 : _1e9 - s % _1e9) << " " << 1 << " " << (s + _1e9 -1) / _1e9 << endl;
}