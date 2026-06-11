#include <iostream>
#include <vector>
#include <string>

using namespace std;

using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vi s(m), c(m);
    for (int i = 0; i < m; i++) {
        cin >> s.at(i) >> c.at(i);
        s.at(i)--;
    }

    for (int i = 0; i < 1000; i++) {
        string t = to_string(i);

        bool f = true;
        if ((int)t.length() == n) {
            for (int j = 0; j < m; j++) {
                if (t.at(s.at(j)) != c.at(j) + '0') {
                    f = false;
                }
            }
        } else {
            f = false;
        }

        if (f) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
