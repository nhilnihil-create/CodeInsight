#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<int> aque;
    for (int i = 0; i < n; i++) {
        aque.push(a[i]);
    }

    for (int i = 0; i < m; i++) {
        int p = aque.top();
        p /= 2;
        aque.pop();
        aque.push(p);
    }

    long s = 0;
    for (int i = 0; i < n; i++) {
        s += aque.top();
        aque.pop();
    }

    cout << s << endl;
}
