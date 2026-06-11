#include<bits/stdc++.h>
#define ll long long
#define maxx 1000005
#define mod 998244353LL
using namespace std;
//ll n, m, k, p, x, y, x1, z1, xt, yt;
string s;
bool check = false;
long long a[1000005], ans, t, b[1000005], m, n, kk, T;

vector<ll> arr;
ll k;
void sol()
{
    cin >> s;
    n = s.length();
    s = " " + s;
    a[0] = 0;
    a[n+1] = 0;
    b[0] = 0;
    b[n+1] = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(s[i] == '<')a[i] = a[i-1] + 1;
        else a[i] = 0;
    }
    for(int i = n-1; i >= 0; i --)
    {
        if(s[i+1] == '<')b[i] = 0;
        else b[i] = b[i+1] + 1;
        //cout << b[i] << '\n';
    }
    for(int i = 0; i <= n + 1; i ++)
    {
        ans += max(a[i], b[i]);
        //cout << max(a[i], b[i]) <<" ";
        }
    cout << ans ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("PAPERS.INP", "r", stdin);
    //freopen("PAPERS.OUT", "w", stdout);
    sol();
}
