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
    vector<ll> v = {1,
                    1,
                    1,
                    2,
                    1,
                    2,
                    1,
                    5,
                    2,
                    2,
                    1,
                    5,
                    1,
                    2,
                    1,
                    14,
                    1,
                    5,
                    1,
                    5,
                    2,
                    2,
                    1,
                    15,
                    2,
                    2,
                    5,
                    4,
                    1,
                    4,
                    1,
                    51};

    int k;
    cin >> k;
    cout << v[k - 1] << endl;
}