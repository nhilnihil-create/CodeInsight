#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main() {
    ll n;
    cin >> n;
    auto pf = prime_factorize(n);
    ll res = 0;
    for(auto p : pf){
        ll prime = p.first;
        ll kazu = p.second;
        ll check = 1;
        while(kazu >= check){
            kazu -= check;
            check++;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}