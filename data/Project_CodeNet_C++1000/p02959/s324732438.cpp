#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
ll l , a[500001];
int main(){
    ll ans = 0;
    int n;
    cin >> n;
    int a[n + 1] , b , c = 0;
    for(int i = 0; i < n + 1; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b;
        ans += min(c , a[i]);
        a[i] = max(a[i] - c , 0);
        ans += min(b , a[i]);
        c = max(b - a[i] , 0);
    }
    ans += min(a[n] , c);
    cout << ans << endl;
}
