#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define dbg(x) cerr << #x << " " << x << "\n"




int main () {
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    int n;
    cin >> n; n--;
    bool poate2 = true;
    int good1 = 0, good2 = 0;
    for (int i = 0; i <= n; i++) {
        char x;
        cin >> x;
        x -= '0';
        x--;
        if (x == 1)
            poate2 = false;
        if ((i & n) == i) {
            if (x == 1)
                good1 ^= 1;
            if (x == 2)
                good2 ^= 2;
        }
    }
    if (good1)
        cout << 1 << '\n';
    else {
        if (good2 && poate2)
            cout << 2 << "\n";
        else
            cout << 0 << "\n";
    }

    return 0;
}
