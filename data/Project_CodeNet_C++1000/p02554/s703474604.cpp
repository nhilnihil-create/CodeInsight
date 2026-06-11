/*
      Ashraful Islam Paran
      16-September-2020
      12:32:31
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f(n) for (int i = 0; i < n; i++)
#define fo(i, x, n) for (int i = x; i < n; i++)
#define fb(i, x, n) for (int i = n - 1; i >= x; i--)
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)

typedef unsigned long long ull;
typedef vector<long long> vi;
#define msi map<string, long long>
#define mii map<long long, long long>
const int MX = 2e5 + 5;
const int mod = 1e9 + 7;
const int INF = 1e18;
#define pb push_back
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(x) x.begin(), x.end()
#define ff first
#define ss second


void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void print(vi &v)
{
    f(v.size())
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int p(int x,int y)
{
    int a=1;
    f(y)
    {
        a=a*x%mod;
    }
    return a;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int ans=p(10,n)-2*p(9,n)+p(8,n);
    ans%=mod;
    if(ans<0)
    {
        ans+=mod;
    }
    cout<<ans<<endl;

    cerr << "Time Killed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}