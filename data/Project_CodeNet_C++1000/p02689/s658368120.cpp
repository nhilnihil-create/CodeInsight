#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    ll h[n];
    for(int i = 0; i < n; ++i) 
        cin >> h[i];
    vector<vector<int>> mp(n);
    while(m--) {
        int a, b;
        cin >> a >> b;
        mp[a-1].push_back(b);
        mp[b-1].push_back(a);
    }

    int ans = 0;
    bool b = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < mp[i].size(); ++j) {
            if(h[i] <= h[mp[i][j] - 1]) {
                b = 0;
                break;
            }
        }
        if(b) 
            ++ans;
        b = 1;
    }

    cout << ans << '\n';

    return 0;
}

