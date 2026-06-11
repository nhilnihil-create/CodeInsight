#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)

int g_bm;

int modl(_LL a)
{
    a %= g_bm;
    if( a < 0 ) a += g_bm * ( 1 - (a + 1) / g_bm );
    return a;
}

int modadd(_LL a, _LL b)
{
    return modl(a + b);
}

int modminus(_LL a, _LL b)
{
    return modl(a - b);
}

int modmul(_LL a, _LL b)
{
    return modl(a * b);    
}

int modinv(_LL a) 
{
    _LL b = g_bm, u = 1, v = 0;
    while (b) 
    {
        _LL t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    return modl(u);
}

int main()
{
    int n, p;
    cin >> n >> p;
    g_bm = p;
    string s;
    cin >> s;
    int *m = new int[p];
    rep(i, p) m[i] = 0;
    _LL ans = 0;
    if( p == 2 || p == 5 )
    {
        // 10と互いに素でない。
        rep(i, n)
        {
            int cs = (s[i] - '0') % p;
            if( cs == 0 ) ans += i + 1;
        }
    }
    else
    {
        _LL k = 1;
        _LL all = 0;
        _LL diff = 0;
        rep(i, n)
        {
            int cs = (s[i] - '0') % p;
            all = modadd(modmul(all, 10), cs);
            m[diff]++;
            int invk = modinv(k);
//            cout << "all : " << all << " k:" << k << " invk:" << invk << endl;
//            cout << modmul(all, invk) << endl;
            ans += m[modmul(all, invk)];
            diff = modadd(diff, modmul(cs, invk));
            k = modmul(k, 10);
            
//            rep(j, p) cout << j << ":" << m[j] << endl;
//            cout << "ans:" << ans << endl;
        }
    }
    cout << ans << endl;        
}