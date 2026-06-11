#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, max_dec_run = 0, curr_run = 0;
    cin >> n;
    int heights[n];
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    for (int i = 1; i < n; i++) {
        if (heights[i] <= heights[i - 1]) {
            curr_run++;
        } else {
            max_dec_run = max(max_dec_run, curr_run);
            curr_run = 0;
        }
    }
    max_dec_run = max(max_dec_run, curr_run);
    cout << max_dec_run;
}
