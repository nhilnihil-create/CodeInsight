#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int maxn = 1e5 + 5;
int main()
{
    ios::sync_with_stdio(false);
    int n ; cin >> n;
    ll ans = 0;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= n ; j++){
            if (i * j >= n) break;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
