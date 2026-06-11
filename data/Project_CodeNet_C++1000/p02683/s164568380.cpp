#include <bits/stdc++.h>
#define ep emplace_back
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>

typedef long long ll;

using namespace std;
int a[15][15];
int price[15];
int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    int n,m,x;
    cin >> n >> m >> x;
    for(int i=0;i<n;++i){
        cin >> price[i];
        for(int j=0;j<m;++j){
            cin >> a[i][j];
        }
    }
    int res = 0x3f3f3f3f;
    int all = 1<<n;
    for(int mask=0;mask<all;++mask){
        vector<int> level(m);
        int cost=0;
        for(int i=0;i<n;++i){
            if ((mask>>i) & 1){
                cost += price[i];
                for(int j=0;j<m;++j){
                level[j] += a[i][j];
                }
            }

        }
        bool ok =true;
        for(auto c:level) {
            if (c<x) ok =false;
        }
        if (ok) res = min (res,cost);

    }
    if(res == 0x3f3f3f3f) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}
