#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n = 0;
    cin >> n;
    vector<ll> cnt(1e5 + 5, 0);
    ll sum = 0;

    for(int i = 0; i < n; i++) {
        int in = 0;
        cin >> in;
        cnt[in]++;
        sum += in;
    }

    int q = 0;
    cin >> q;
    while(q--) {
        int a = 0, b = 0;
        cin >> a >> b;

        sum -= (cnt[a] * a);
        sum += (b * cnt[a]);

        cnt[b] += cnt[a];
        cnt[a] = 0;

        cout << sum << endl;
    }



    
    return 0;
}