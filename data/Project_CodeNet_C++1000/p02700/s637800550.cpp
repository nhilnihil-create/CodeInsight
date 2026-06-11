#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a , b, c, d;
    cin >> a >> b >> c >> d;
    while(a > 0 && c > 0) {
        c = c - b;
        if(c <= 0) {
            cout << "Yes" << "\n";
            return 0;
        }
        a = a - d;
        if(a <= 0) {
            cout << "No" << "\n";
            return 0;
        }
    }
    if(a > c)
        cout << "Yes" << "\n";
    else
        cout << "No" << "\n";

    return 0;
}
