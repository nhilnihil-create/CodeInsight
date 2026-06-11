#include "bits/stdc++.h"
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int r[n + 1], c[m + 1];
    map<pair<int, int>, int> grid;

    memset(r, 0, sizeof r);
    memset(c, 0, sizeof c);

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        grid[make_pair(x, y)] = 1;
        r[x]++, c[y]++;
    }
    int x, y;

    int temp = -1;
    for (int i = 1; i <= n; i++)
        if (temp < r[i]) {
            temp = r[i];
            x = i;
        }
    vector<int> xs, ys;
    for (int i = 1; i <= n; i++)
        if (r[i] == temp) xs.push_back(i);
    temp = -1;

    for (int i = 1; i <= m; i++)
        if (temp < c[i]) {
            temp = c[i];
            y = i;
        }
    for (int i = 1; i <= m; i++)
        if (c[i] == temp) ys.push_back(i);
    int ans = 0;
    bool f=false;
    for(int x : xs){
        for(int y : ys ){
            int temp=r[x]+c[y];
            if(!grid[make_pair(x,y)]){
                ans=temp;
                f=true;
                break;
            }
            else ans=temp-1;
        }
        if(f)break;
    }
    cout<<ans<<endl;
}

