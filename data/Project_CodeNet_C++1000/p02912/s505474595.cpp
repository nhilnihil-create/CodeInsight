#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    multiset<int> money;
    int a;

    rep(i,n){
        cin >> a;
        money.insert(a);
    }

    rep(i,m){
        auto itr = money.end();
        itr--;
        money.insert(*itr / 2);
        money.erase(itr);
    }

    ll ans = 0;
    for(auto itr = money.begin(); itr != money.end(); itr++){
        ans += *itr;
    }

    cout << ans << endl;
    return 0;
}