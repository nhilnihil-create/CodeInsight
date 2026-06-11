#include <iostream>
#include <iomanip>
#include <vector>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<vector<ll>> num(10, vector<ll>(10, 0));
    repi(i, n + 1, 1)
    {
        vector<int> d;
        ll nn = i;
        while(nn){
            d.push_back(nn % 10);
            nn /= 10;
        }
        ll a = d[0];
        ll b = d.back();
        if(!a || !b)continue;
        num[a][b]++;
    }
    repi(a,10,1){
        repi(b,10,1){
            res += num[a][b] * num[b][a];
        }
    }
    cout << res << endl;
    return 0;
}