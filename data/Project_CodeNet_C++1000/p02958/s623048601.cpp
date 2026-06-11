#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;
    vector<int> pi(n);
    vector<int> sorted(n);
    rep(i, n) {
        int N;
        cin >> N;
        pi.at(i) = N;
        sorted.at(i) = N;
    }
    sort(sorted.begin(), sorted.end());

    int cnt = 0;
    rep(i, n) {
        if (pi.at(i) != sorted.at(i))
            cnt++;
    }
    if (cnt == 0 || cnt == 2)
        cout << "YES";
    else
        cout << "NO";
}