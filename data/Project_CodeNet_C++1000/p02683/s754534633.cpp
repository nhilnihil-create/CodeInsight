#include <iostream>

using namespace std;
const int N = 20;
int n,m,x;
int a[N][N],c[N],sum[N];
int main()
{
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    long long ans = 1e18;
    for (int i = 1; i <= (1 << n) - 1; i++){
        fill(sum + 1,sum + 1 + n,0);
        long long coin = 0;
        for (int temp = 0; temp < n; temp++)
            if ((i >> temp) & 1 == 1){
                coin = coin + c[temp + 1];
                for (int j = 1 ; j <= m; j++) sum[j] += a[temp + 1][j];
            }
        bool check = true;
        for (int j = 1; j <= m; j++)
            if (sum[j] < x) check = false;
        if (check) ans = min(ans , coin);
    }
    cout << ((ans == 1e18) ? -1 : ans);
    return 0;
}
