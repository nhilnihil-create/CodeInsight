#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vpli vector<pair<long long, int>>
#define deb(x) cout <<"deb "<<#x<<" "<< x << endl;
#define all(x) x.begin(), x.end()
ll MOD = 1e9 + 7;
const int INF = 2e9 + 10;
void solve()
{
    string s;
    cin>>s;
    for(char &x : s) x = 'x';
    cout<<s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}