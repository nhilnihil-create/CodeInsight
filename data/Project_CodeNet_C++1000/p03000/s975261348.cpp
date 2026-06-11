#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , x;
int l[MAXX];
int a[MAXX];

int main()
{
    _FastIO;
    cin >> n >> x;
    int ans = 1;
    for(int i = 0; i < n; i++){
        cin >> l[i];
        a[i + 1] = a[i] + l[i];
        if(a[i + 1] <= x)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
