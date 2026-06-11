#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    int n; cin >> n;
    int64_t k; cin >> k;
    vector<int> a(n);
    for (auto &e : a) cin >> e;

    int ct, cs, cn;
    {
        vector<int> visited(n, -1);
        visited[0] = 0;

        int w = 0;
        while (visited[a[w] - 1] == -1) {
            visited[a[w] - 1] = visited[w] + 1;
            w = a[w] - 1;
        }

        ct = visited[a[w] - 1];
        cs = a[w] - 1;
        cn = visited[w] + 1 - visited[a[w] - 1];
    }

    if (k < ct) {
        int cur = 0;
        while (k--) {
            cur = a[cur] - 1;
        }
        cout << cur + 1 << endl;
        return 0;
    }

    k -= ct;

    int cnt = k % cn;
    int cur = cs;
    while (cnt--) {
        cur = a[cur] - 1;
    }

    cout << cur + 1 << endl;
}

