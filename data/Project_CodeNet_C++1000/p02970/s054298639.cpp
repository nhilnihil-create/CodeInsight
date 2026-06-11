#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , d;

int main()
{
    _FastIO;
    cin >> n >> d;
    int k = 2 * d + 1;
    int ans = n / k;
    if(n % k) ans++;
    cout << ans << endl;
    return 0;
}
