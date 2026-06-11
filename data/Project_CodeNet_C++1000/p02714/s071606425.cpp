#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    string s;
    cin >> n >> s;

    long long num_r=0, num_g=0, num_b=0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') num_r++;
        else if (s[i] == 'G') num_g++;
        else if (s[i] == 'B') num_b++;
    }

    int eq = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            int k = (j - i) + j;
            if (k >= n) continue;
            if (s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) eq++;
        }
    }

    long long ans = num_r*num_g*num_b - eq;
    cout << ans << endl;
    return 0;
}
