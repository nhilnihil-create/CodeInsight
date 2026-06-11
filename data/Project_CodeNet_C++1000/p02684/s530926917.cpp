#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    deque<int> q;
    vector<bool> seen(n, false);
    int cur = 0;
    while (true) {
        if (seen[cur]) {
            while (cur != q[0]) {
                k--;
                q.pop_front();

                if (k == 0) {
                    cout << q[0]+1 << endl;
                    return 0;
                }
            }
            break;
        }

        q.push_back(cur);
        seen[cur] = true;
        cur = a[cur];
    }

    cout << q[k % q.size()] + 1 << endl;
    return 0;
}
