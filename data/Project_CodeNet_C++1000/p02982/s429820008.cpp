#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int square(int a) { return a * a; }

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> x.at(i).at(j);
        }
    }

    int cnt = 0;
    int dis = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dis = 0;
            for (int k = 0; k < d; k++) {
                dis += square(x.at(i).at(k) - x.at(j).at(k));
            }
            for (int k = 0; k * k <= dis; k++) {
                if (dis == k * k) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}