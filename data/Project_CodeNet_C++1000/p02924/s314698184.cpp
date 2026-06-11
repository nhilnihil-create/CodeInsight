#include<bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define sloop(i, s, n) for (int i = s; i < n; i++)
#define rloop(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int n, ans = 0;
    cin >> n;
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    n--;
    ans = (n*(n+1))/2ll;
    cout << ans << endl;
    return 0;
}
