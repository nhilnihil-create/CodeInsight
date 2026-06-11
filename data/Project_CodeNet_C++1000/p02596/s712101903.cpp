#include <iostream>
#include <cstdlib>
#include <bitset>
#include <map>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecchar vector<char>
#define vecstr vector<string>
#define vec2str vector<vector<string>>
#define vecbool vector<bool>
#define vec2bool vector<vector<bool>>
#define pairll pair<ll,ll>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)

#define Pi 3.1415926535897932384626

int main() {
	ll k,ans=-1;
	string s;
	bool flag = false;

	cin >> k;

	ll buf=0;
	ll count = 0;

	while(1)
	{
		buf = (7 + buf * 10) % k;

		count++;

		if (count > k)
		{
			ans = -1;
			break;
		}

		if (buf == 0)
		{
			ans = count;
			break;
		}

	}

	cout << ans;
}