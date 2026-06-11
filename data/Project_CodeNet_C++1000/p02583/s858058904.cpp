#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector< int >L(n);
    for (int &x : L) cin >> x;

    sort(L.rbegin(), L.rend());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (L[i]==L[j]) continue;
            for (int k = j+1; k < n; k++) {
                if (L[j]==L[k]) continue;
                ans += L[j]+L[k] > L[i];
            }
        }
    }

    cout << ans << endl;


    return 0;
}
