#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define all(v) v.begin(), v.end()
#define repi(i, n, init) for (ll i = init; i < (n); i++)
#define repd(i, n, init) for (ll i = (n); i >= init; i--)
#define repm(i, m) for (auto i = m.begin(); i != m.end(); i++)

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll length = 0;
    repi(i, N, 0)
    {
        cin >> A[i];
        length += A.at(i);
    }
    
    ll t1 = A.at(0),t2 = length - A.at(0);
    ll ans = abs(t1 - t2);
    repi(i,N,1){
        t1 += A.at(i);
        t2 -= A.at(i);
        ans = min(ans,abs(t1-t2));
        
    }
    cout << ans << endl;
    return 0;
}