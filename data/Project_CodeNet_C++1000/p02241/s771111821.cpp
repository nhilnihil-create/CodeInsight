#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    int adj[n][n];
    int inf = 2001;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int k; cin >> k;
            adj[i][j] = k == -1 ? inf : k;
        }
    }

    int sd[n] = {1};
    int ans = 0;

    while(true) {
        int a = -1, c = inf;

        for(int i = 0; i < n; i++) {
            if(sd[i] == 0) { 
                if(a == -1) {
                    a = i;
                }
                continue;
            }
            for(int j = 0; j < n; j++) {
                if(adj[i][j] < c && sd[j] == 0) {
                    c = adj[i][j];
                    a = j;
                }
            }
        }

        if(a == -1) break;

        ans += c;
        sd[a] = 1;
    }

    cout << ans << endl;

}