///BE NAME KHODA
#include <bits/stdc++.h>

using namespace std;

#define S second
#define F first
#define int long long

typedef long long ll;
typedef long double ld;

const int maxn = 1e6+10;
const int mod = 998244353;
const ll inf = 1e9+10;

int n, m, k;
int a[maxn], fac[maxn];

signed main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    fac[0] = 0;
    for(int i = 1; i < maxn; i++)
    {
        int cnt = 0, j = i;
        while(!(j&1)){j >>= 1; cnt++;}
        fac[i] = fac[i-1] + cnt;
    }

    cin>> n;
    string s; cin>> s;
    int X = 0, z = 0;
    for(int i = 0; i < n; i++)
    {
        if(i < n-1)
        if(abs(s[i]-s[i+1]) == 1)
            X = 1;
        if(((s[i]-'0') & 1) && !(fac[n-1] - fac[i] - fac[n-1-i]))
            z ^= 1;
    }
    if(z)
        cout<< 1;
    else
        if(X)
            cout<< 0;
        else
        {
            int ans = 0;
            for(int i = 0; i < n-1; i++)
                if((abs(s[i]-s[i+1]) == 2) && !(fac[n-2] - fac[i] - fac[n-i-2]))
                {
                    ans ^= 2;
                }
            cout<< ans;
        }
}


