#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; i++)
#define ll long long

using namespace std;

int main() {
    string S;
    cin >> S;
    ll size = S.size()+1;
    vector<int> left(size);
    vector<int> right(size);

    ll num;
    
    num = 0;
    for (int i = 0; i < size; i++) {
        left[i] = num;
        if (i < size-1 && S[i] == '<')
            num++;
        else
            num = 0;
    }

    num = 0;
    for (int i = size-1; i >= 0; i--) {
        right[i] = num;
        if (i > 0 && S[i-1] == '>')
            num++;
        else
            num = 0;
    }

    ll ans = 0;
    rep(i, size) {
        ans += max(left[i], right[i]);
    }

    cout << ans << endl;
}
