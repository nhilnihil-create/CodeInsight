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


    int n = 0, m = 0, x = 0;
    cin >> n >> m >> x;
    vector< pair<int, vector<int> > > v(n, make_pair(0, vector<int> (m, 0)));

    for(int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        vector<int> tmp;
        for(int j = 0; j < m; j++) {
            int tm;
            cin >> tm;
            tmp.push_back(tm);
        }

        v[i] = make_pair(temp, tmp);
    }

    vector<int> algo;
    long long int ans = 1e18;
    for(int i = 0; i < (1 << n); i++) {
        long long cnt = 0;
        algo.assign(m , 0);
        for(int j = 0; j < n; j++) {
            if((i >> j & 1)) continue;
            cnt += v[j].first;
            for(int k = 0; k < m; k++) {
                algo[k] += v[j].second[k];
            }   
        }
        
        int check = 1;
        // for(int j = 0; j < m; j++) {
        //     cout << algo[j] << " ";

        // }
        // cout << endl;
        for(int j = 0; j < m; j++) {
            if(algo[j] < x) check = 0;
        }
        if(check) {
            ans = min(ans, cnt);
        }
    }

    if(ans == 1e18) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}