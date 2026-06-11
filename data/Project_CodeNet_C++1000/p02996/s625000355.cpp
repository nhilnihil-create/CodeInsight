#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 200005

ll n;
ll a[MAXX];
ll b[MAXX];

int main()
{
    _FastIO;
    cin >> n;
    bool flag = true;
    multiset<pair<ll , ll> > ms;
    multiset<pair<ll , ll> >::iterator it;
    for(ll i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        if(a[i] > b[i]) flag = false;
        ms.insert({b[i] , i});
    }
    if(!flag){
        cout << "No" << endl;
        return 0;
    }
    ll t = 0;
    string ans = "Yes";
    for(it = ms.begin(); it != ms.end(); it++){
        ll x = (it)->second;
        t += a[x];
        if(t > b[x]){
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
