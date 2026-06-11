#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define pii pair<int, int>
#define vpli vector<pair<long long, int>>
#define deb(x) cout << "deb " << #x << " " << x << endl;
#define all(x) x.begin(), x.end()
#define endl "\n"
const int mx = 1e5 + 1;

void swap(ll &a, ll &b)
{
    ll t = a;
    a = b;
    b = t;
}

ll Min(ll a, ll b, ll c)
{
    return min(a, min(b, c));
}

void printvec(vi &vec)
{
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
}

int sum(int a)
{
    int ans = 0;
    while (a)
    {
        ans += (a % 10);
        a = a / 10;
    }
    return ans;
}
void print(vi & mp)
{
    for(auto x : mp)
    {
        cout<<x;
    }
    cout<<endl;
}
void solve()
{
    int a,b;
    cin>>a>>b;
    cout<<a*b<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}