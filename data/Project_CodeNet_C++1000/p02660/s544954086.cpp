#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

//素因数分解
vector<pair<ll, int>> factorize(ll n) {
    vector<pair<ll, int>> res;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i) continue;
        res.emplace_back(i, 0);
        while(n % i == 0) {
            n /= i;
            res.back().second++;
        }
    }
    if(n != 1) res.emplace_back(n, 1);
    return res;
}

int main()
{
    ll n;
    cin >> n;

    vector<pair<ll, int>> f = factorize(n);
    
    ll ans = 0;
    for(auto u : f) {
        int num = u.second;
        int i = 1;
        while(i <= num) {
            num -= i;
            ans++;
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}
