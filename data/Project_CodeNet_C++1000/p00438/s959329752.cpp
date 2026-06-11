#include<stdio.h>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <map>     
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <iomanip>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define ld long double
#define loop(a,t) for(int a=0;a<t;a++) 
#define forever while(true)
#define Sort(a) sort(a.begin(),a.end())
#define Reverse(a) reverse(a.begin(),a.end())

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	forever{
		int a, b;
	
		int n;
		cin >> a >> b;
		if (a == 0 && b == 0) { break; }
		bool out[16][16];
		int dp[16][16];
		loop(i, 16) {
			loop(j, 16) {
				out[i][j] = false;
				dp[i][j] = 0;
			}
		}
		cin >> n;
		loop(i, n) {
			int p, q;
			cin >> p >> q;
			out[p - 1][q - 1] = true;
		}

		dp[0][0] = 1;
		loop(i, a) {
			loop(j, b) {
				if (!out[i][j])
				{
					if (i != 0) { dp[i][j] += dp[i - 1][j]; }
					if (j != 0) { dp[i][j] += dp[i][j - 1]; }
				}
			}
		}
		cout << dp[a - 1][b - 1] << endl;
	}
	return 0;
}
