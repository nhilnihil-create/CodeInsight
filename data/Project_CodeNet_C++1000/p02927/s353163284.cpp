//Problem: JSC2019 Qual A
//Progress: Working
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, ans = 0;
    cin >> n >> m;
    for(ll i=22; i<=m; i++)
        if(i%10 >= 2 && (i/10) >= 2 && i%10 * (i/10) <= n)
            ans++;
    cout << ans;
    return 0;
}