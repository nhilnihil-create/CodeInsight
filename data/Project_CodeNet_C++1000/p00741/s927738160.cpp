#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int x[90][90], col[90][90], h, w, c, i, j, k, l, p, q;
queue<int>Q, R;
int main() {
	while (true) {
		c = 0;
        memset(x,0,sizeof(x));
		memset(col, 0, sizeof(col));
		cin >> w >> h;
		if (h == 0) { break; }
		for (i = 0; i < h; i++) { for (j = 0; j < w; j++) { cin >> x[i][j]; } }
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				if (x[i][j] == 1 && col[i][j] == 0) {
					c++;
					col[i][j] = c;
					Q.push(i * 100 + j);
					while (!Q.empty()) {
						while (!Q.empty()) {
							p = Q.front() / 100;
							q = Q.front() % 100;
							for (k = -1; k < 2; k++) {
								for (l = -1; l < 2; l++) {
									if (x[p + k][q + l] == 1 && col[p + k][q + l] == 0) {
										col[p + k][q + l] = c;
										R.push((p + k) * 100 + q + l);
									}
								}
							}
							Q.pop();
						}
						while (!R.empty()) {
							Q.push(R.front());
							R.pop();
						}
					}
				}
			}
		}
		cout << c << endl;
	}
}