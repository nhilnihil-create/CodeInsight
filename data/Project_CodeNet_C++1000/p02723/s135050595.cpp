#include<iostream>
#include<queue>
#include<memory>
#include<map>
#include<set>
#include<unordered_map>
#include<array>
#include<vector>
#include<algorithm>
#include<list>
#include<limits>
#include<stdio.h>
#include<math.h>
#include<string>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using lst = list<ll>;
using pr  = pair<ll, ll>;

const ll MOD = 998244353;

int main()
{
	string S;
	cin >> S;

	if (S[2] == S[3] && S[4] == S[5])
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}