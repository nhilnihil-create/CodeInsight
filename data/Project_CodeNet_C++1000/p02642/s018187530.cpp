#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+7;
int fr[MAXN];
int okay[MAXN];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        fr[a]++;
        okay[a] = 1;
    }

    int ans = 0;
    for (int a = 1; a < MAXN; a++) {
        if (fr[a] > 0)  {
            for (int b = a+a; b < MAXN; b += a) {
                okay[b] = 0;
            }
        }
        ans += okay[a] && (fr[a] == 1);
    }

    cout << ans << endl;



    return 0;
}
