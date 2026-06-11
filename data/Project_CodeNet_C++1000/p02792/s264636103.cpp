#include<bits/stdc++.h>
using namespace std;
#define MAXN 200010
int dp[MAXN];
int cnt[10][10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    int c = 0;
    for(int i = 1; i <= n; i++){
        int a, b;
        b = i % 10;
        int x = i;
        while(x >= 10)
            x /= 10;
        a = x;
        ans += cnt[b][a];
        cnt[a][b]++;
        if(a == b) c++;
    }
    ans = ans * 2 + c;
    cout << ans << "\n";

    return 0;
}