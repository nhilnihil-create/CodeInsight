#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>
#define rep(i, j) for(int i = 0; i < j; i++)
#define all(i) i.begin(), i.end()
using namespace std;
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
struct axis { int x, y; };
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;  while (cin >> N && N != 0)
	{
		vector<axis> dat(N + 2);
		axis mx; mx.x = 0, mx.y = 0;
		axis mn; mn.x = 0, mn.y = 0;
		for(int i = 1; i < N; i++)
		{
			int pic = 0, dir = 0; cin >> pic >> dir;
			dat[i].x = dat[pic].x + dx[dir];
			dat[i].y = dat[pic].y + dy[dir];
			mx.x = max(mx.x, dat[i].x);
			mx.y = max(mx.y, dat[i].y);
			mn.x = min(mn.x, dat[i].x);
			mn.y = min(mn.y, dat[i].y);
		}
		printf("%d %d\n", abs(mx.x) + abs(mn.x) + 1, abs(mx.y) + abs(mn.y) + 1);
	}
}