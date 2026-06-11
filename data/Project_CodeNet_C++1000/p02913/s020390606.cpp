#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second
const int N = 5e3+5 , mod=1e9+7;
const int b = 37;
const int b2 = 31;
int pw[N] , inv[N] , pw2[N] , inv2[N];
pair<int,int> prefix[N] , prefix2[N];
int n;
string s;

int mul(int a, int b)
{
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (1ll * a * b) % mod;
}

int add(int a, int b)
{
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (a + b) % mod;
}

int fastpow(int base, int power)
{
    if(!power)
        return 1;
    int ret = fastpow(base, power / 2);
    ret = mul(ret, ret);
    if(power & 1)
        ret = mul(ret, base);
    return ret;
}

void pre()
{
    pw[0] = inv[0] = pw2[0] = inv2[0] =1;
    int mul_inv = fastpow(b, mod - 2);
    int mul_inv2 = fastpow(b2, mod - 2);
    for(int i = 1; i < N; i++)
    {
        pw[i] = mul(pw[i - 1], b), inv[i] = mul(inv[i - 1], mul_inv);
        pw2[i] = mul(pw2[i - 1], b2), inv2[i] = mul(inv2[i - 1], mul_inv2);
    }
}

pair<int,int> getHash(int l , int r)
{
    int res = prefix[r].f , res2 = prefix[r].s;
    if (l) res = add(res , -prefix[l-1].f) , res2 = add(res2 , -prefix[l-1].s);
    res = mul(res , inv[l]) , res2 = mul(res2 , inv2[l]);
    return {res,res2};
}

void calc()
{
    for(int i=0; i<s.size(); i++)
    {
        if (i) prefix[i] = prefix[i-1];
        prefix[i].f = add(prefix[i].f , mul(s[i]-'a'+1 , pw[i]));
        prefix[i].s = add(prefix[i].s , mul(s[i]-'a'+1 , pw2[i]));
    }
}

bool check(int len)
{
    map< pair<int,int> , int> mp;
    for(int i=0; i+len-1<n; i++)
    {
        int l=i , r = i+len-1;
        pair<int,int> pr = getHash(l,r);
        if (!mp.count(pr)) mp[pr] = r;
        else
        {
            if (mp[pr] < i) return 1;
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    pre();

    cin >> n >> s;
    calc();

    int l=1 , h=n , mid , idx=0;
    while(l<=h)
    {
        mid = (l+h)/2;
        if (check(mid))
        {
            idx = max(idx , mid);
            l = mid+1;
        }
        else h=mid-1;
    }

    cout << idx << '\n';

    return 0;
}