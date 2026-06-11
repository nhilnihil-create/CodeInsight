#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, x, y;
int d[2000][2000];
vector<vector<int>> v;

void diikstra(int s) {
    queue<int> q;
    q.push(s);
    int c;
    while (!q.empty()) {
        c = q.front();
        q.pop();
        for (int a : v[c]) {
            if (d[s][a] > d[s][c] + 1) {
                d[s][a] = d[s][c] + 1;
                q.emplace(a);
            }
        }

    }
}

int main() {
    cin >> n >> x >> y;
  	for (int i = 0; i < n; i++) {
    	v.emplace_back(vector<int>());
    }
    for (int i = 1; i < n; i++) {
        v[i].emplace_back(i-1);
        v[i-1].emplace_back(i);
    }
  	
    v[x-1].emplace_back(y-1);
    v[y-1].emplace_back(x-1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                d[i][j] = 0;
            } else {
                d[i][j] = 2001;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        diikstra(i);
    }
    int ks[n];
    for (int i = 0; i < n; i++) ks[i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] < n) ks[d[i][j]]++;
        }
    }
    for (int i = 1; i < n; i++) {
        cout << ks[i]/2 << endl;
    }
    return 0;
}