#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x,n; cin >> x >> n;
    map<int,int> mp;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        mp[a] = 1;
    }
    if (!mp[x]) {
        cout << x; return 0;
    }
    int i = x + 1;
    int j = x - 1;
    bool ok = true;
    while(ok) {
        if (!mp[j]) {
            cout << j; return 0;
        }
        if (!mp[i]) {
            cout << i; return 0;
        }
        i++;
        j--;
    }
}