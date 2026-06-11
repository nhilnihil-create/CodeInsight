#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    double A, V;
    cin >> A >> V;
    double B, W;
    cin >> B >> W;
    double T;
    cin >> T;
    if (A <= B) {
        double time = (B - A) / (V - W);
        if (time >= 0 && time <= T) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        double time = (A - B) / (V - W);
        if (time >= 0 && time <= T) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}