#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end() 
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repr(i, a, b) for(int i = a - 1; i >= b; i--)
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define iterr(m) for(auto it = m.rbegin(); it != m.rend(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
signed main(){
    speed;
    int n; cin >> n;
    vector<vector<pair<int, int>>> data(n);
    int sz = n;
    rep(j, 0, n) {
        int m; cin >> m;
        vector<pair<int, int>> v(m);
        rep(i, 0, m) {
            int x, y; cin >> x >> y;
            v[i] = {x, y};
        }
        data[j] = v;
    }
    n = sz;
    int ans = 0;
    for(int i = 0; i < (1 << n); i++) {
        vector<int> v(n);
        vector<int> visited(n, -1);
        bool yes = true;
        int k = i;
        int cnt = 0;
        while(k != 0) {
            v[cnt] = k % 2;
            k /= 2;
            cnt++;
        }

        for(int i1 = 0; i1 < n; i1++) {
            if(v[i1]) {
                if(visited[i1] == 0) yes = false;
                for(int j1 = 0; j1 < data[i1].size(); j1++) {
                    int loc = data[i1][j1].first - 1;
                    int condition = data[i1][j1].second;
                    if(visited[loc] == -1 && v[loc] == condition) {
                        visited[loc] = condition;
                    } else {
                        if(visited[loc] != condition || v[loc] != condition) {
                            yes = false;
                        }
                    }
                }
            }
        }
        cnt = 0;
        k = i;
        while(k != 0) {
            cnt += k % 2;
            k /= 2;
        }
        if(yes) {
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;

    return 0;
}