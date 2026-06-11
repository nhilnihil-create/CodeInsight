#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define all(a) a.begin(), a.end()
#define sz(a) a.size()
using namespace std;

int n, m, k, b=0, ans=0;
char a[6][6];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("A.txt", "r", stdin);
    #endif
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j]=='#') b++;
        }
    }
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<(1<<m); j++){
            int tb=b;
            for(int k=0; k<n; k++){
                for(int l=0; l<m; l++){
                    if(a[k][l]=='#'&&((i&(1<<k))||(j&(1<<l)))) tb--;
                }
            }
            if(tb==k) ans++;
        }
    }
    cout << ans << endl;
}
