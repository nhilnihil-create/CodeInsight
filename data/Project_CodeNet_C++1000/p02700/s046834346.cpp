#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h1, s1, h2, s2;
    cin >> h1 >> s1 >> h2 >> s2;

    int need1=(h2+s1-1)/s1,
        need2=(h1+s2-1)/s2;

    cout << (need1<=need2 ? "Yes" : "No");

    return 0;
}
