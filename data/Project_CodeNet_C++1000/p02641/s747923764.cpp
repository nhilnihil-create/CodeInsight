#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
    int x, n;
    cin >> x >> n;

    int a[205];
    fill_n(a, 205, 1);

    int mn = INT_MAX, val;
    for(int i = 0; i<n; i++)
    {
        int c;
        cin >> c;
        a[c]--;
    }

    if(a[x])
    {
        cout << x << endl;
        return ;
    }

    int i = x-1;
    while(a[i]!=1)
    {
        i--;
    }

    int j = x+1;
    while(a[j]!=1)
    {
        j++;
    }
    if(x-i>j-x)
    {
        cout << j << endl;
    }
    else cout << i << endl;

}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    solve();
    return 0;
}
