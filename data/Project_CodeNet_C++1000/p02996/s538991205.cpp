#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> task;
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        task.push_back(make_pair(b, -a));
    }
    sort(task.begin(), task.end());

    ll t = 0;
    rep(i, n)
    {
        t += -task[i].second;
        if (t > task[i].first) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}