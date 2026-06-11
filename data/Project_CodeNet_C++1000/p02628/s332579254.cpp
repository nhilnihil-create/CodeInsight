#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    int sum = 0;
    for(int i = 0; i<k; i++)
    {
        sum += a[i];
    }

    cout << sum << endl;

}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    solve();
    return 0;
}
