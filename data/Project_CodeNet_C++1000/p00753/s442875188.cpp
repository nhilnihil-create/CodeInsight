#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <set>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>
#include <list>
#include <map>
#include <functional>
#include <iterator>

#define rep(i,p,n) for(int i=(int)p;i<(int)n;i++)
#define repp(i,p,n) for(int i=(int)p;i>=(int)n;i--)
#define Sort(x) sort(x.begin(),x.end())
#define PSort(x) sort(begin(x), end(x), pairCompare)
#define ll long long
#define INF 2000000000
#define pb push_back
#define mp make_pair
#define PI 3.14159265358979
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
using namespace std;

int main(){
	int dp[123456 * 2 + 1] = { 0 };
	dp[1] = 1;
	dp[2] = 1;
	rep(i, 3, 123456 * 2 + 1) {
		bool f = true;
		if (i % 2 == 0)f=false;
		else {
			for (int j = 3; j <= sqrt(i);j+=2) if (i%j == 0)f = false;
		}
		if (f)dp[i] = 1;
	}

	while (1) {
		int x,ans=0;
		cin >> x;
		if (x == 0)break;
		rep(i, x + 1, 2 * x + 1)if (dp[i] == 1)ans++;
		cout << ans << endl;
	}


	

	return 0;
}