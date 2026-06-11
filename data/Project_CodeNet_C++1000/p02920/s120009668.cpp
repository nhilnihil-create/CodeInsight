#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

typedef deque<int> qi;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int s[1<<n];
    for (int i = 0; i < 1 << n; i++) {
        cin >> s[i];
    }
    sort(s, s+(1<<n));
    reverse(s, s+(1<<n));

    qi q[n+1];
    q[n].push_back(s[0]);
    for (int i = 1; i < 1 << n; i++) {
        bool f = false;
        for (int j = n; j >= 1; j--) {
            if (!q[j].empty() && q[j].front() > s[i]) {
                q[j-1].push_back(s[i]);
                q[j-1].push_front(q[j].front());
                q[j].pop_front();
                f = true;
                break;
            }
        }

        if (!f) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
