#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define len(a) a.size()

using namespace std;

typedef long long ll;

int main()
{
    int a, b, c, k; cin >> a >> b >> c >> k;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k - i; j++) {
            int q = (1 << i);
            int w = (1 << j);
            if (a < b * q && b * q < c * w) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}
