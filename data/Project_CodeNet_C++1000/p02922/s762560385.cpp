#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int A, B;
    cin >> A >> B;

    int ans = 0;
    int outlet = 1;

    while (outlet < B)
    {
        outlet -= 1;
        outlet += A;
        ans++;
    }

    cout << ans << endl;

    return 0;
}