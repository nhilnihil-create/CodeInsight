#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

int main() {
	while (true) {
		int a[21][21] = {}, X = 10, Y = 10;

		int N, M;
		cin >> N; if (!N)break;
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			a[x][y] = 1;
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			char c;
			int z;
			cin >> c >> z;

			if (c == 'N')for (int j = 1; j <= z; j++) a[X][Y + j] = 0;
			else if (c == 'E')for (int j = 1; j <= z; j++) a[X + j][Y] = 0;
			else if (c == 'S')for (int j = 1; j <= z; j++) a[X][Y - j] = 0;
			else if (c == 'W')for (int j = 1; j <= z; j++) a[X - j][Y] = 0;

			if (c == 'N') { Y += z; }
			else if (c == 'E') { X += z; }
			else if (c == 'S') { Y -= z; }
			else if (c == 'W') { X -= z; }

		}
		bool No = false;
		for (int i = 0; i < 21; i++)
			for (int j = 0; j < 21; j++)
				if (a[i][j])
					No = true;
		if (No)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}