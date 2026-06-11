
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    --a;
    int res = 1;
    int cnt = 0;
    while (res < b) {
        res += a;
        ++cnt;
    }
    cout << cnt << endl;

    return 0;
}

