#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const int mxn = 1e7+2;

void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> a(n+1, 0);
    for(ll i = 1; i<=n; i++)
    {
        for(int j = i; j<=n; j+=i)
        {
            a[j]++;
        }
    }
    for(ll i = 1; i<=n; i++)
    {
        sum += (ll)a[i]*i;
    }

    cout << sum;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
