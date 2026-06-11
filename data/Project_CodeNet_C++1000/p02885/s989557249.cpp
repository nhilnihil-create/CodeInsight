
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    cout << max(0, a - b * 2) << endl;

    return 0;
}

