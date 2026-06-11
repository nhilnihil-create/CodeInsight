#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    pair<int, bool> card[3][3];
    int n;
    int a;
    int b;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a;
            card[i][j] = make_pair(a, false);
        }
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> b;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (card[j][k].first == b) {
                    card[j][k].second = true;
                    break;
                }
            }
        }
    }

    if (card[0][0].second && card[1][1].second && card[2][2].second) {
        cout << "Yes" << endl;
        return 0;
    }

    if (card[0][2].second && card[1][1].second && card[2][0].second) {
        cout << "Yes" << endl;
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        if (card[i][0].second && card[i][1].second && card[i][2].second) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (card[0][i].second && card[1][i].second && card[2][i].second) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}