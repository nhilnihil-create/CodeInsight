#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , sum , s;
int a[MAXX];

int main()
{
    _FastIO;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int ans = 10005;
    for(int i = 0; i < n; i++){
        s += a[i];
        int  k = abs(2 * s - sum);
        ans = min(ans , k);
    }
    cout << ans << endl;
    return 0;
}
