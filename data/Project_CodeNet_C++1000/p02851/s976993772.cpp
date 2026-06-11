#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
ll A[200005], S[200005];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A[i]--;
        S[i + 1] = (S[i] + A[i] + k) % k;
    }

    ll ans = 0;
    
    map<int, int> mp;

    for(int i = 0; i <= n; i++){
        if (i - k >= 0) mp[S[i - k]]--;
        ans += mp[S[i]];
        mp[S[i]]++;
    }
    cout << ans << endl;
    return 0;
}