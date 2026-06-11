#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <ctime>
#include <complex>
#include <bitset>
#include <tuple>

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define MOD 1000000007LL

using namespace std;
using llong = long long;

int main()
{
	IOS;
	
	int n, m;
	cin >> n >> m;
	int i;
	set<string> ac;
	int pen = 0;
	int accnt = 0;
	
	map<string, int> penpen;
	for (i = 1; i <= m; i++)
	{
		string p, acwa;
		cin >> p >> acwa;
		if (ac.count(p) == 0 && acwa == "WA") penpen[p]++;
		else if (ac.count(p) == 0 && acwa == "AC")
		{
			accnt++;
			if (penpen.count(p) != 0) pen += penpen[p];
			ac.insert(p);
		}
	}
	cout << accnt << " " << pen;
	return 0;	
}

