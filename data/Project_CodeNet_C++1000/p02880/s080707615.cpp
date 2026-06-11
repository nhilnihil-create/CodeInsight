#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int  i = 1; i  <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            if( i * j == n) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}
