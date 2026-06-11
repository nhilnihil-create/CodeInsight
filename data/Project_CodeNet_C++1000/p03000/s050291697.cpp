#include <iostream>
#include <vector>
#include <cmath>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
typedef long long ll;

int main()
{
    ll n, x;
    ll ans = 0;
    ll cnt = 0;
    ll l = 0;
    cin >> n >> x;
    vector <ll> L(n, 0);
    for (int i = 0; i < n; i ++){
        cin >> L.at(i);
    }
    while (l<=x){
        l += L[cnt];
        cnt += 1;
        if (cnt==n+1) break;
    }
    ans = cnt;
    cout << ans << endl;
    return 0;
}