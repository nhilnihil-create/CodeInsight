#include "bits/stdc++.h"

#define pii pair < int, int > 

#define pb push_back
#define pf push_front
#define pB pop_back()
#define pF pop_front()

using namespace std;

int n, m;
char s[105][105];
int dst[105][105];
int drr[] = {0, 1};
int drc[] = {1, 0};

bool chk(int i, int j)
{
	if(i < 0 || j < 0 || i >= n || j >= m) return 0;

	return 1;
}

void bfs()
{
	for(int i = 0; i < 105; i++) fill(dst[i], dst[i] + 105, 1e9);

	deque < pii > dq;
	
	if(s[0][0] == '.') dst[0][0] = 0;
	else dst[0][0] = 1;

	dq.pb({0, 0});

	while(!dq.empty()){
		pii cur = dq.front();
		dq.pF;

		int x = cur.first, y = cur.second;

		for(int i = 0; i < 2; i++){
			int r = x + drr[i], c = y + drc[i];

			if(chk(r, c)){
				int weight = 0;

				if(s[x][y] == '.' && s[r][c] == '#') weight = 1;

				if(dst[r][c] > dst[x][y] + weight){
					dst[r][c] = dst[x][y] + weight;

					if(weight == 0) dq.pf({r, c});
					else dq.pb({r, c});
				}
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	 	freopen("output.txt", "w", stdout);
	#endif

	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cin >> s[i][j];
	}

	bfs();

	cout << dst[n - 1][m - 1] << endl;

	return 0;
}