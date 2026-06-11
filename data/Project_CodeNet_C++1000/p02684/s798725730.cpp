#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void print(vector<int> v) {
    for (auto x : v) cout << x << " ";
    cout << endl;
}

int main()
{
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
    }

    vector<int> cur(1, 1);
    vector<int> visited(n + 1, -1);
    visited[1] = 0;
    long long pos = -1;

    for (int i = 0; i < n + 1; i++) {
        int x = a[cur[i]];

        if (visited[x] >= 0) {
            pos = visited[x];
            break;
        }
        visited[x] = i + 1;
        cur.push_back(x);
    }

    if (k <= pos) {
        cout << cur[k] << endl;
    } else {
        int loop = cur.size() - pos;
        cout << cur[(k - pos) % loop + pos] << endl;
    }
    return 0;
}