#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1200005;
int main(){
    int n, m, x;
    cin >> n >> m >> x;
    int c[n], a[n][m];
    for(int i = 0; i < n; i++){
        cin >> c[i];
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    int ans = inf;
    for(int bit = 0; bit < (1 << n); bit++){
        int s = 0;
        vector<int> al(m);
        for(int i = 0; i < n; i++){
            if(1 & (bit >> i)){
                s += c[i];
                for(int j = 0; j < m; j++){
                    al[j] += a[i][j];
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; i++)
            if(al[i] >= x)
                cnt ++;
        if(cnt == m)
            ans = min(ans, s);
    }
    if(ans == inf)
        ans = -1;
    cout << ans << endl;
    return 0;
}