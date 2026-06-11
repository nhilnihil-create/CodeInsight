#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a;
    string s;
    cin >> a >> s;
    if(a >= 3200) {
        cout << s;
    } else if(a < 3200) {
        cout << "red";
    }

    return 0;
}
