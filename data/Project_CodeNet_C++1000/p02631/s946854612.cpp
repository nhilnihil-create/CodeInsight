#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 998244353
#define int long long
#define ll long long
#define EPS 0.000000001
#define ld long double
#define inf 5e18
#define N 500000
#define K 17



int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    vector<int> v(n + 1);
    int sum = 0;
    for(int i = 1;i <= n;i++)
    {

        cin >> v[i];
        sum ^= v[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cout << (sum ^ v[i]) << " ";
    }
    return 0;
    
}   