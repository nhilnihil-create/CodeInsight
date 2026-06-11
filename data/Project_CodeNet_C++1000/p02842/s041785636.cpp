#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        ll tmp = i * 1.08;
        if (tmp == n)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":("<<endl;
}