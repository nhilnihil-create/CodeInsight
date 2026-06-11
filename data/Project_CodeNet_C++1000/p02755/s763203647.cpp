#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    int a, b; cin >> a >> b;

    for (int i=1;i<=1000;i++) {
        int x = i*0.08, y = i*0.1;
        if (x==a&&y==b) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
