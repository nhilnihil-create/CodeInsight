#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;

vector<pair<ll,int>> pf(ll n) {
    vector<pair<ll,int>> a;

    for(ll i = 2; i*i <= n; i++) {

        int ex = 0;

        while(n%i == 0) {
            ex++;
            n /= i;
        }
        a.push_back({i,ex});

        
    }
    if(n != 1) a.push_back({n,1});

    return a;
}

int main() {

    ll n; cin >> n;
    vector<pair<ll,int>> p;
    p = pf(n);
    int ans = 0;
    for(ll i = 0; i < p.size(); i++) {
        int cnt = 1;
        int tmp = p[i].second;
        while(tmp>=cnt) {
            ans++;
            tmp -= cnt;
            cnt++;
        }
    }

    cout << ans << endl;

	return 0;
}
