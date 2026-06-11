#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    ll a[n];

    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    sum += *max_element(a, a+n);

    int take = 0, j = n - 2;
    for(int i = 0; i < n - 2; i++)
    {
        take++;
        sum += a[j];
        if(take > 1)
        {
            j--;
            take = 0;
        }
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
