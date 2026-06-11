#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        u--;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            v--;
            edges[u][v] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                cout << " ";
            }
            cout << edges[i][j];
        }
        cout << endl;
    }
}