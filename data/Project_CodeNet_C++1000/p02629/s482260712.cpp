#include <bits/stdc++.h>
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define unmap unordered_map<int, int>
#define unset unordered_set<int>
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define pb push_back
#define ll long long
#define ull unsigned ll
#define ff first
#define ss second //typedef second ss;
#define foton(i, n) for (int i = 0; i < n; i++)
#define faton(i, a, n) for (int i = a; i <= n; i++)
#define mod 1000000007
#define endl "\n"
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    string ans = "";
    while (n > 0)
    {
        n -= 1;
        ans += char('a' + (n % 26));
        n = floor(n / 26);
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}

int main()
{
    fastio;
    solve();
    return 0;
}