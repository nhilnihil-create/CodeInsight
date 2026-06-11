#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll A; double B; cin >> A >> B;
	ll B100 = (ll)(B*100+0.001);
	cout<<A*B100/100<<"\n";

	return 0;
}
