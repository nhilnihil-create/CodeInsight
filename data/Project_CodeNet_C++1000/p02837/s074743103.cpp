#include <bits/stdc++.h>
#define lli long long int
#define timesave ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


void solve()
{
    int n;
    cin >> n;

    vector< pair<int,int> > v[n+5];

    for(int i = 0; i < n; i++){
        int a, x, y;
        cin >> a;

        while(a--){
            cin >> x >> y;
            v[i].push_back({x, y});
        }
    }

    int mx = 0;

    for(int i = 0; i < (1<<n); i++){
        int flag = 0;

        for(int j = 0; j < n; j++){
            if((i & (1<<j))){
                int l = v[j].size();

                for(int k = 0; k < l; k++){
                    int x = v[j][k].first, y = v[j][k].second;
                    int d;
                    if((i & (1<<(x-1)))) d = 1;
                    else d = 0;
                    if(d != y) {flag = 1; break;}
                }
                if(flag) break;
            } 
        }

        if(!flag){
            //cout << i << "\n";
            int cnt = __builtin_popcount(i);
            mx = max(mx, cnt);
        }
    }

    cout << mx << "\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //timesave; 
    
    int tc = 1;
    //cin >> tc;
    while(tc--) solve();
 
    return 0;
}