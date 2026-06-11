#include <iostream>
#define ll long long
using namespace std;
const int N = 5009;
int n,k;
int p[N],c[N],sp[N],avail[N];
long long f[N][N];
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++){
        memset(avail,0,sizeof(avail));
        int j = i , cnt = 0;
        while (avail[p[j]] == 0){
            cnt++;
            f[i][cnt] = f[i][cnt - 1] + c[p[j]];
            avail[p[j]] = 1;
            j = p[j];
        }
        sp[i] = cnt;
    }
    ll ans = -1e18;
    for (int i = 1; i <= n; i++){
        ll pos_max = 0 , val = -1e18;
         for (int j = 1; j <= min(sp[i],k); j++)
            if (f[i][j] > val){
                val = f[i][j];
                pos_max = j;
            }
        ans = max(ans,f[i][pos_max] + 1LL * ((k - pos_max)/sp[i]) * f[i][sp[i]]);
        ans = max(ans , 1LL * (k/sp[i]) * f[i][sp[i]] + f[i][k % sp[i]]);
        ans = max(ans,f[i][pos_max]);
    }
    cout << ans;
}