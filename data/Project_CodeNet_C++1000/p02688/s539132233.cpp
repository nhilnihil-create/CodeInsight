#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long int
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define prec(n) fixed << setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define PI 3.1415926535897932384626
#define bits(n) __builtin_popcount(n)

bool snuck[101];

void solve()
{
    memset(snuck,false,sizeof(snuck));
    int n,k;
    cin>>n>>k;

    for(int i=0;i<k;i++)
    {
        int d;
        cin>>d;
        for(int j=0;j<d;j++)
        {
            int a;
            cin>>a;
            snuck[a]=true;
        }
    }
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(!snuck[i])
        c++;
    }
    cout<<c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}