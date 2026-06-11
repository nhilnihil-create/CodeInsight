#include<bits/stdc++.h>
using namespace std;



void solve()
{
    int x, t, n;
    cin >> n >> x >> t;
    int ans;
    int times;
    if (n%x==0)
        times = n/x;
    else
        times = n/x+1;
    ans = times*t;
    cout << ans;
}

int main()
{

    solve();
    cout << "\n";

}


