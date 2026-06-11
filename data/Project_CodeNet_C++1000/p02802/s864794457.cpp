#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<bool> flag(n, false);
    vector<int> wa(n);

    int ac = 0, penalty = 0;
    for (size_t i = 0; i < m; i++) {
        int p;
        string s;
        cin >> p >> s;

        if (s == "AC" && !flag[p-1]) {
            ++ac;
            flag[p-1] = true;
            penalty += wa[p-1];
        }else if (s == "WA" && !flag[p-1]) {
            ++wa[p-1];
        }
    }

    cout << ac << ' ' << penalty << endl;
    return 0;
}
