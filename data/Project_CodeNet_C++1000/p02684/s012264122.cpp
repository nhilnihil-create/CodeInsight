#include <iostream>
#include <vector>
#include <deque>

using namespace std;
int n;
long long k;

int main() {
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> p; // path
    vector<int> d(n + 1, -1); // discovered
    int cycle_len = 1, acyclic_len = 0;
    {
        int v = 1, t = 0;
        while (d[v] == -1) {
            // visit the vertex
            d[v] = t;
            t++;
            p.push_back(v);

            // move to the next vertex
            v = a[v - 1];
        }
        cycle_len = t - d[v];
        acyclic_len = d[v];
    }

    if (k <= acyclic_len) {
        cout << p[k] << endl;
    } else {
        k -= acyclic_len;
        k %= cycle_len;
        k += acyclic_len;
        cout << p[k] << endl;
    }
    return 0;
}