#include <bits/stdc++.h>

using namespace std;
#define N 200200

long long v[N], w[N];
long long ans, prv;
int i, n;
int main()
{
    cin >> n;
    ++n;
    for (i = 0; i < n; ++i)
        cin >> v[i];
    for (i = 1; i < n; ++i)
        cin >> w[i - 1];
    prv = 0;
    --n;
    for (i = 0; i < n; ++i){
        if (prv > v[i]){
            ans += v[i];
            prv = 0;
            v[i] = 0;
        }
        else{
            ans += prv;
            v[i] -= prv;
            prv = 0;
        }
        if (w[i] > v[i]){
            ans += v[i];
            prv = w[i] - v[i];
        }
        else{
            ans += w[i];
            prv = 0;
        }
    }
    ans += min(prv, v[i]);
    cout << ans;
    return 0;
}
