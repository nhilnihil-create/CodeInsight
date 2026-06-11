#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int a[n];
    vector<int> v(1000001, 0);
    int ones = 0;

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        v[a[i]]++;
        if(a[i] == 1)
        {
            ones++;
        }
    }
    if(ones > 1)
    {
        cout << 0 << endl;
        return ;
    }
    if(ones == 1)
    {
        cout << 1 << endl;
        return ;
    }
    sort(a, a+n);
    int ans = 0;
    for(int x :a)
    {
        if(v[x] == 1)
        {
            ans++;
        }

        for(int i = x; i<1000001; i+=x)
        {
            v[i]++;
        }
    }
    cout << ans << endl;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
