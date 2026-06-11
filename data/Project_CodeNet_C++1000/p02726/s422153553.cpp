#include <bits/stdc++.h>
#define int long long

#define mp make_pair
#define pb push_back
#define mod (int)1e9+7
using namespace std;

signed main(){
    int n;
    cin >> n;
    int x,y;
    cin >> x >> y;
    int cnt[n+1];
    memset(cnt,0,sizeof cnt);
    x--;
    y--;
    for(int i = 0;i<n;i++){
        for(int z = i+1;z<n;z++){
            int res = z-i;
            res = min(res,abs(i-x)+1+abs(z-y));
            res = min(res,abs(i-y)+1+abs(z-x));
            cnt[res]++;
        }
    }
    for(int i = 1;i<n;i++){
        cout << cnt[i] << endl;
    }
}
