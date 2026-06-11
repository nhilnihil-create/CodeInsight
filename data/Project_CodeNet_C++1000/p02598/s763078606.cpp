#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const int sz = 2e5+5;
int a[sz];

bool bs(int mid, int k)
{
    for(int x :a)
    {
        //how many cuts to get to less than mid?
        if(x<mid) continue;
        int cuts = (x+mid-1)/mid;
        k -= cuts-1;
    }
    return k >= 0;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> a[i];

    int mn = 1, mx = 1e9 + 7;

    while(mn != mx)
    {
        int mid = (mn+mx)/2;
        if(bs(mid, k))
            mx = mid;
        else
            mn = mid+1;
    }
    cout << mn << endl;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
