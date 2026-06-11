
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
const int MOD = 1e9+7,mxN = 50,INF = 1e9;
int n,q;


void solve()
{
    ll a,b;
    cin >> a >> b;
    cout << (a*b)/__gcd(a,b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    
}
