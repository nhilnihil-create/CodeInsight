#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
void Main()
{
    int n;
    cin >> n;
    string c;
    cin >> c;

    int left = 0;
    int right = n - 1;
    int cnt = 0;
    while (true) {
        for (; left < n; left++) {
            if (c[left] == 'W') {
                break;
            }
        }
        for (; right >= 0; right--) {
            if (c[right] == 'R') {
                break;
            }
        }

        if (left >= n || right < 0 || right <= left) {
            break;
        }

        swap(c[left], c[right]);
        cnt++;
    }
    put(cnt);
}
signed main(){ Main();return 0;}