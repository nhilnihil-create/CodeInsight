#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    vector<vector<int>> v(3, vector<int>(3));
    rep(i, 3) {
        rep(j, 3) {
            cin >> v.at(i).at(j);
        }
    }

    int n;
    cin >> n;

    rep(i, n) {
        int b;
        cin >> b;

        rep(j, 3) {
            rep(k, 3) {
                if (v.at(j).at(k) == b)
                    v.at(j).at(k) = 0;
            }
        }
    }

    rep(i, 3) {
        int s = 0;

        rep(j, 3)
            s += v.at(i).at(j);

        if (s == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    rep(i, 3) {
        int s = 0;

        rep(j, 3)
            s += v.at(j).at(i);

        if (s == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    int s;

    s = 0;
    rep(i, 3)
        s += v.at(i).at(i);

    if (s == 0) {
        cout << "Yes" << endl;
        return 0;
    }

    s = 0;
    rep(i, 3)
        s += v.at(i).at(2 - i);

    if (s == 0) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
}
