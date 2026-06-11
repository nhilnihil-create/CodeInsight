#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    cin >> N;

    int p[N];
    rep(i, N) cin >> p[i];

    int k = 0;

    rep(i, N) {
        if (p[i] != i+1) {
            k++;
        }
            
    }

    if (k <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}