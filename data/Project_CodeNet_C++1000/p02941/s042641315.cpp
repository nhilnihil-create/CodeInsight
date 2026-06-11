#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long
#define F first
#define S second
#define pii pair<int,int>
#define mpr make_pair

const int maxn = 2e5+10;
const int mod = 998244353;
//const ll inf = 1e9+10;

/*int pw(int a, int b)
{
    if(b == 0) return 1;
    int x = pw(a,b/2); x = (x * 1ll * x) % mod;
    if(b & 1) x = (x * 1ll * a) % mod;
    return x;
}*/

int n, A[maxn], B[maxn];
set<pii> se;

void kill()
{
    cout<< -1;
    exit(0);
}

signed main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n;
    for(int i = 1; i <= n; i++) cin>> A[i];
    for(int i = 1; i <= n; i++)
    {
        cin>> B[i];
        se.insert({B[i],i});
    }

    int ans = 0;
    while(se.size())
    {
        auto it = se.end(); it--;
        int i = (*it).S, M = (*it).F;

        int left = i-1; if(left == 0) left = n;
        int right = i+1; if(right == n+1) right = 1;
        int x = B[left];
        int y = B[right];

        se.erase({B[i],i});
        if((A[i] % (x+y)) == (B[i] % (x+y)))
        {
            ans += (B[i] - A[i]) / (x+y);
            B[i] = A[i];
            continue;
        }

        if(B[i] <= (x+y)) kill();
        ans += B[i] / (x+y);
        B[i] %= (x+y);
        if(B[i] == 0) return cout<< -1, 0;
        se.insert({B[i],i});
    }
    cout<< ans;
}


