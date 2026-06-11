#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h.at(i);

    int max_cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        int j, cnt = 0;
        for (j = i; j < n - 1; j++) {
            if (h.at(j) < h.at(j + 1))
                break;
            else
                cnt++;
        }

        i = j;

        max_cnt = max(max_cnt, cnt);
    }

    cout << max_cnt << endl;
}