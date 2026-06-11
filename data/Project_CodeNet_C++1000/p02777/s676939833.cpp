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
    string s[2];
    cin>>s[0]>>s[1];
    int c1,c2;
    cin>>c1>>c2;
    string t;
    cin>>t;
    if(t==s[0]) c1--;
    else c2--;
    cout<<c1<<" "<<c2;
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