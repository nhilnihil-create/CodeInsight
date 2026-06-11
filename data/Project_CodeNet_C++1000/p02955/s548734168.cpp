#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int n, k, a[1000];

int main()
{
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    int sum = 0;
    rep(i, n) sum += a[i];

    vector<int> g(0);
    for(int i = 1; i * i <= sum; i++)
    {
        if(sum % i == 0)
        {
            g.emplace_back(i);
            g.emplace_back(sum / i);
        }
    }
    sort(g.begin(), g.end(), greater<int>());

    int res = 0;
    for(auto x : g)
    {
        int b[n];
        rep(i, n) b[i] = a[i] % x;
        sort(b, b + n, greater<int>());
        int sum = 0;
        rep(i, n) sum += b[i];
        int tmp = 0;
        rep(i, sum / x) tmp += b[i];
        sum -= tmp;
        if(sum <= k)
        {
            cout << x << endl;
            break;
        }
    }
    return 0;
}