#include <bits/stdc++.h>

using namespace std;
int n,m,k,sum = 0;
char a[10][10];
bool avail[10][10];
void reset(){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) avail[i][j] = false;
}
int main(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++){
            a[i][j] = s[j - 1];
            if (a[i][j] == '#') sum++;
        }
    }
    for (int i = 0; i <= n; i++) a[i][0] = '.';
    for (int j = 0; j <= m; j++) a[0][j] = '.';
    int ans = 0;
    for (int i = 0; i < (1LL << (n + 1)); i += 2)
        for (int j = 0; j < (1LL << (m + 1)); j += 2){
            reset();
            int cnt = 0;
            for (int mask = 0; mask <= n; mask++)
                if ((i >> mask) & 1 == 1){                
                    for (int cj = 1; cj <= m; cj++)
                        if (avail[mask][cj] == false && a[mask][cj] == '#'){
                        avail[mask][cj] = true;
                        cnt++;
                        }
                }            
            for (int mask = 0; mask <= m; mask++)
                if ((j >> mask) & 1 == 1){                  
                    for (int ci = 1; ci <= n; ci++)
                        if (avail[ci][mask] == false && a[ci][mask] == '#'){
                            avail[ci][mask] = true;
                            cnt++;
                        }
                }
            if (sum - cnt == k) ans++;
        }
    cout << ans;
    return 0;
}