



    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define FAST ios_base::sync_with_stdio(false);cin.tie(0);
    const double EPS = 1e-9;
    const double PI = acos(-1);
    const int knightDir[8][2] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{2,1},{-1,-2},{1,-2}};
    //const int dx[]={0,0,0,1,1,1,-1,-1,-1};
    //const int dy[]={-1,0,1,-1,0,1,-1,0,1};
    const int dx[] = {0 , 1 , 0 , -1};
    const int dy[] = {1 , 0 , -1 , 0};
    //#define MOD         1000000007LL
    #define MAX         1000005
    const ll MOD = 1000000000 + 7;
    ll pows(ll x , ll n)
    {
        ll ans = 1;
        for(int i = 1 ; i <= n ; i++)
        {
            ans *= x;
            ans = ans % MOD;
        }
        return ans;
    }
    int main()
    {
        FAST
        int t;
        t = 1;

        while(t--)
        {
           ll n;
           cin >> n;
           ll ans = (pows(10 , n) - (2 * pows(9 , n)) + pows(8 , n)) % MOD;
           ans += MOD;
           cout << ans % MOD << endl;
        }
    }

