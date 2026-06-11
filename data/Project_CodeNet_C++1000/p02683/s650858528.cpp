#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI 3.14159265358979323846264338327950L

int n,m,x,cc,aa;
int a[12][12];
int c[12];
int tmp[12];

void solve(){

    cin >> n >> m >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> cc;
        c[i] = cc;
        for (int j = 0; j < m; j++)
        {
            cin >> aa;

            a[i][j] = aa;

        }
        
    }
    
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans = 0;
        for (int j = 0; j < n; j++)
        {
            ans += a[j][i];
        }
        
        if(ans < x){
            cout << -1 << endl;
            return;
        }
    }
    
    ans = 1000000000000;
    ll tans = 0;
    for (ll i = 0; i < (1<<n); i++)
    {
        tans = 0;
        bool flag = true;
        for (int h = 0; h < m; h++) tmp[h] = 0;
        

        for (int j = 0; j < n; j++)
        {
            if(i & (1<<j)){
                tans +=c[j];
                for (int h = 0; h < m; h++) tmp[h] += a[j][h];                
            }
        }
        
        for (int h = 0; h < m; h++){
            if(tmp[h] < x){
                flag = false;
            }
        }    
        if(flag) ans = min(ans, tans);
    }
    
    cout << ans << endl;
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}