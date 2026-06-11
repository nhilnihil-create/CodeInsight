#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	int n;
	string s, t;
	cin >> n >> s >> t;
	rep(i, n)
	{
		cout << s[i] << t[i];
	}
	cout << "\n";
	return 0;
}