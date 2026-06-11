#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , ans;
int a[MAXX];
int b[MAXX];
int c[MAXX];

int main()
{
    _FastIO;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        ans += b[i];
    }
    for(int i = 1; i <= n - 1; i++){
        cin >> c[i];
    }
    for(int i = 2; i <= n; i++){
        if(a[i] == (a[i - 1] + 1))
            ans += c[a[i - 1]];
    }
    cout << ans << endl;
    return 0;
}
