#include <bits/stdc++.h>
#include <iostream>
#include <time.h>
using namespace std;
int g_bm = 1000000007;

#define _LL long long

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

int modpow(_LL a, _LL b)
{
    int prebit = modl(a);
    int ans = 1;
    for( int bit = 0; (long unsigned int) b >= (1UL << bit); bit++ )
    {
        if( bit > 0 ) prebit = modmul(prebit, prebit);
        if( b & (1UL << bit) ) ans = modmul(ans, prebit);
    }
    return ans;
}

int modcalcsub(_LL a, _LL b, char c)
{
    switch(c)
    {
        case '+':
            return modadd(a, b);
        case '-':
            return modminus(a, b);
        case '*':
            return modmul(a, b);
    }
    return 0;
}

int modsublevel(char c)
{
    switch(c)
    {
        case '+':
        case '-':
            return 0;
        case '*':
            return 1;
    }
    return 0;
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

int modcalc(_LL a1, char c1, _LL a2, char c2 = 0, _LL a3 = 0, char c3 = 0, _LL a4 = 0, char c4 = 0, _LL a5 = 0, char c5 = 0, _LL a6 = 0, char c6 = 0, _LL a7 = 0, char c7 = 0)
{
    char c[8] = {c1, c2, c3, c4, c5, c6, c7, '0'};
    _LL a[8] = {a1, a2, a3, a4, a5, a6, a7, 0};
    int ans[4];
    char prec[4];
    int level = 0;
    int index = 0;
    ans[0] = 0;
    prec[0] = '+';
    // 3 + 4 * 8 + 3
    while( prec[level] != '\0' )
    {
        int nlevel = modsublevel(c[index]);
        while( level < nlevel )
        {
            ans[level + 1] = 0;
            prec[level + 1] = '+';
            level++;
        }        
        ans[level] = modcalcsub( ans[level], a[index], prec[level]);
        while( nlevel < level )
        {
            ans[level - 1] = modcalcsub( ans[level - 1], ans[level], prec[level - 1]);
            level--;
        }
        prec[level] = c[index++];
    }
    return ans[0];
}

void addbitsum(_LL a, _LL *s0, _LL *s1, int d)
{
    for( _LL k = 0 ; k < 60; k++ )
    {
        if( a & (1LL << k) )
        {
            s1[k] += d;
        }
        else
        {
            s0[k] += d;
        }
    }

}

int main()
{
    _LL n;
    cin >> n;
    _LL *a = new _LL[n];
    for( _LL i = 0; i < n; i++ ) cin >> a[i];
    _LL sumj0[64];
    _LL sumj1[64];
    for( _LL k = 0 ; k < 64; k++ ) sumj0[k] = 0, sumj1[k] = 0;
    for( _LL j = 0; j < n; j++ ) addbitsum( a[j], sumj0, sumj1, 1);
    _LL ans = 0;
    for( _LL i = 0; i < n - 1; i++ )
    {
        addbitsum( a[i], sumj0, sumj1, -1);
        _LL bitpow = 1;
        for( _LL k = 0 ; k < 60; k++ )
        {
            _LL tmp = (a[i] & (1LL << k)) ? sumj0[k] : sumj1[k];
            ans = modadd( ans, modmul(tmp, bitpow % 1000000007) );
            bitpow = (bitpow << 1);
        }
    }
    cout << ans << endl;
    delete a;
}