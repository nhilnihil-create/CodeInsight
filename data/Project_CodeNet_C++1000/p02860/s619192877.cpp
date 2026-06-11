#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    if(n % 2 == 1) {
        cout << "No" << "\n";
        return 0;
    }
    int flag = 1;
    for(int i = 0; i < n / 2; i++) {
        if(s[i] != s[i + n / 2]) {
            flag = 0;
            break;
        }
    }
    if(flag == 1)
        cout << "Yes" << "\n";
    else
        cout << "No" << "\n";
    return 0;
}
