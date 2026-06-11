
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
const int MOD = 1e9+7,mxN = 50,INF = 1e9;
int n,q;


void solve()
{
    cin >> n;
    int curr=1,ans = 0;
    while(n--)
    {
        int a;
        cin >> a;
        if(a == curr)
            curr++;
        else ans++;
    }
    if(curr==1)
        cout << "-1\n";
    else
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    
}
