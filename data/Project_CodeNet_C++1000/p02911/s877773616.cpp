#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n , k , q;
    cin >> n >> k >> q;

    vector<int> s(n + 1 , 0);
    for (int i = 0 ;i < q ;i++) {
        int x;
        cin >> x;
        s[x]++;
    }

    for (int i = 1 ;i <= n ;i++) {
        if (k - q + s[i] > 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
