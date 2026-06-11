#include <bits/stdc++.h>

using namespace std;



void solver() {
    int n; cin >> n;
    
    vector<int> a(n), pref(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i] = a[i];
        if (i) pref[i] ^= pref[i - 1];
    }
    vector<int> suff(n);
    for(int i = n - 1; i >= 0; --i) {
        suff[i] = a[i];
        if (i + 1 < n) suff[i] ^= suff[i + 1];
    }

    for(int i = 0; i < n; ++i) {
        int L = (i ? pref[i - 1] : 0);
        int R = (i + 1 < n ? suff[i + 1] : 0);
        cout << (L ^ R) << " \n"[i == n - 1];
    }

}

int main() {

    ios_base :: sync_with_stdio(0); cin.tie(NULL);

    int t = 1;
    //cin >> t;
    
    while(t--)
        solver();

    return 0;
}