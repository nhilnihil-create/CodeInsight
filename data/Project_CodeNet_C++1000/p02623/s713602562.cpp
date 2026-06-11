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
#define forllde(s,a) for(long long s = a;s >= 0;s--)

#define Pi 3.1415926535897932384626

int main() {
	ll n,m,k,ans=0;
	string s="No";
	bool flag = false;

	cin >> n >> m >> k;

	vecll a(n), b(m);

	forll(i, 0, n)
		cin >> a[i];

	forll(i, 0, m)
		cin >> b[i];

	vecll minA(n + 1,0), minB(m + 1,0);

	forll(i, 0, n)
		minA[i + 1] = minA[i] + a[i];

	forll(i, 0, m)
		minB[i + 1] = minB[i] + b[i];

	ll now = m;

	forll(i, 0, n+1)
	{
		forllde(j, now)
		{
			if (minA[i] + minB[j] <= k)
			{
				now = j;
				ans = max(ans, i + j);
				break;
			}
		}
	}

	cout << ans;
}