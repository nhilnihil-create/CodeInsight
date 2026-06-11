#include <iostream>
#include <sstream>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <bitset>
#include <stack>
#include <queue>
#include <ctype.h>
#include <list>

typedef long long int lli;
#define rep(i,s,N) for(int i=s;i<N;i++)
#define MOD 1000000007
#define more(a,b) (((a)>(b))?(a):(b))
#define less(a,b) (((a)<(b))?(a):(b))
template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;

int main(void)
{
	int N; cin >> N;
	map<int, int> cnt; cnt[0] = 0;
	rep(i, 0, N) {
		int tmp; cin >> tmp;
		cnt[tmp]++;
	}
	map<int, int>::iterator it = cnt.begin(); it++;
	bool flag = false;
	if (cnt[0] == N)flag = true;
	else if ( cnt[0] == N / 3 && it->second == N * 2 / 3)flag = true;

	if (cnt[0] == 0)cnt.erase(0);
	if (cnt.size() == 3) {
		it = cnt.begin();

		map<int, int>::iterator a = cnt.begin(); a++;
		map<int, int>::iterator b = cnt.begin(); b++; b++;
		if (it->second == N / 3 && a->second == N / 3 && b->second == N / 3) {
			if ((it->first ^ a->first ^ b->first)== 0)flag = true;
		}
	}


	cout << (flag ? "Yes" : "No") << endl;

	return 0;
}
