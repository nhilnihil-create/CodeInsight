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
#define N 305
#define K 17







int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> basis;

        for(int i = 0;i < n;i++)
            cin >> v[i];
        string s;
        cin >> s;

        bool ans = 0;
        for(int i  = n - 1;i >= 0;i--)
        {
            for(auto it : basis)
                if( (v[i] ^ it) < v[i])
                    v[i] ^= it;
            if(v[i])
            {
                if(s[i] == '1')
                {
                    ans = 1;
                    break;
                }
                else
                    basis.push_back(v[i]);
            }
        }
        cout << ans << endl;
    }

    
    return 0;
    
}   