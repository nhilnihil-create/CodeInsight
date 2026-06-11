#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

void factorization(vector<LLP>& llp, ll n) {
    if (n <= 1) return;
    ll n2 = n;
    for (ll i = 2; i * i <= n ; i++) {
        int count = 0;
        while (n2 % i == 0) {
            n2 = n2 / i;
            count ++;
        }
        if (count > 0) {
            LLP temp;
            temp.first = i;
            temp.second = count;
            llp.push_back(temp);
        }
    }
    if (n2 > 1) {
        LLP temp;
        temp.first = n2;
        temp.second = 1;
        llp.push_back(temp);
    }
}

int main() {

    long long N;
    cin >> N;

    ll ans = 0;
    if (N > 2) {
        ll count = 1;
        vector<LLP> fac;
        factorization(fac, N - 1);
        rep(i,fac.size()) {
            count *= fac[i].second + 1;
        }
        ans += count - 1;
    }
    for (ll i = 2; i * i <= N; i++) {
        if (N % i != 0) continue;
        if (i * i < N) {
            ll j = N / i;
            ll n = N;
            while (n % i == 0) n /= i;
            if (n % i == 1) ans++;
            n = N;
            while (n % j == 0) n /= j;
            if (n % j == 1) ans++;
        } else ans++;
    }

    ans++;

    cout << ans << endl;
    
    return 0;
}