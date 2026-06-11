#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 1e9 + 1
#define INF_LL 1LL<<60
#define ll long long

#define MAX_V 105

#define MAX_N 100
#define MAX_M 100

vector<ll> yakusu_a;
vector<ll> yakusu_b;

int main(){
    ll n;
    cin >> n;

    vector<ll> yakusu_a;
    vector<ll> yakusu_b;
    yakusu_a.push_back(n);
    yakusu_b.push_back(n-1);

    if(n==2) {
        cout << "1" << endl;
        return 0;
    }

    REPN(i, 2, sqrt(n)+1) {
        if(n % i == 0) {
            yakusu_a.push_back(i);
            if(i*i != n) yakusu_a.push_back(n/i);
        }
    }

    REPN(i, 2, sqrt(n-1)+1) {
        if((n-1) % i == 0) {
            yakusu_b.push_back(i);
            if(i*i != n-1) yakusu_b.push_back((n-1)/i);
        }        
    }

    ll ans = yakusu_b.size();
    
    REP(i, yakusu_a.size()) {
        ll tmp = n;
        while(1) {
            if(tmp % yakusu_a[i] == 0) tmp = tmp / yakusu_a[i];
            else break;
        }
        if(tmp % yakusu_a[i] == 1) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}