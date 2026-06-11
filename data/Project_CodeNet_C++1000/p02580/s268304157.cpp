#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;
ll n, m, k;
const ll NMAX = 300005;
ll ival[NMAX], jval[NMAX];

ll vx[NMAX], vy[NMAX];

ll imax = -1, jmax = -1;
ll cnt = 0;
ll mmax = -1;
ll valx, valy;

int main()
{
    ll i, x, y;
    cin >> n >> m >> k; valx = valy = 0;
    for(i = 1; i <= k; i++) {
        cin >> x >> y;
        vx[i] = x; vy[i] = y;
        ival[x]++;
        jval[y]++;
        if(ival[x] > imax) {
            imax = ival[x];
            valx = 1;
        }
        else if(imax == ival[x])
            valx++;
        if(jval[y] > jmax) {
            jmax = jval[y];
            valy = 1;
        }
        else if(jmax == jval[y])
            valy++;
    }
    cnt = valx * valy;
    for(i = 1; i <= k; i++) {
        if(imax + jmax == ival[vx[i]] + jval[vy[i]]) {
            cnt--;
        }
    }
    if(cnt > 0) {
        cout << imax + jmax;
    } else {
        cout << imax + jmax - 1;
    }
    return 0;
}
