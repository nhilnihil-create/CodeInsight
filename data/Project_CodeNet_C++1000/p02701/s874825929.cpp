#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
#include<iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(n,x) for(ll i=0;i<n;i++) cin>>x[i];


int main()
{
	ll n;
	cin >> n;
	set<string> a;
	string s;
	for (ll i = 0; i< n; i++)
	{
		cin >> s;
		a.insert(s);
	}
	cout << a.size() << "\n";

	return 0;
}