#include <bits/stdc++.h>
#define rep(i,d) for (int i = 0; i < (d); i++);
using namespace std;
using ll = long long;


int main() {
    int m, d;
    cin >> m >> d;

    int ans = 0;

    for (int j = 1; j <= m; j++)
        for (int i = 20; i <= d; i++){
            if ((i % 10) < 2) continue;
            if ((i / 10) * (i % 10) == j){
                ans++;
            }
    }

    cout << ans << endl;
}