#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long
#define rep(i, n) for(_LL i = 0; i < (_LL)(n); i++)
int g_bm = 1000000007;

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

class ModFactorial
{
public:
    int m_max;
    int *m_factorial;
    int *m_factorialinv;

    ModFactorial(int max)
    {
        m_max = max + 1;
        m_factorial = (int*) malloc(sizeof(int) * m_max );
        m_factorialinv = (int*) malloc(sizeof(int) * m_max );
 
        m_factorial[0] = 1;
        for( int k = 1; k < m_max; k++) m_factorial[k] = modmul(k, m_factorial[k - 1]);
        m_factorialinv[m_max - 1] = modinv( m_factorial[m_max - 1] );
        for( int k = m_max - 1 ; k > 0; k--) m_factorialinv[k - 1] = modmul(k, m_factorialinv[k]);
    }

    ~ModFactorial()
    {
        free(m_factorial);
        free(m_factorialinv);
    }

    int getFactorial(int n)
    {
        return m_factorial[n];
    }

    int getFactorialInv(int n)
    {
        return m_factorialinv[n];
    }

    int getCombination(int n, int r)
    {
        return modcalc(m_factorial[n], '*', m_factorialinv[r], '*', m_factorialinv[n - r]);
    }
};


int main()
{
    int x, y;
    cin >> x >> y;
    int n = x + y;
    int m = n / 3;
    int mx = x - m;
    int my = y - m;

    if( n % 3 != 0 || mx < 0|| my < 0 )
    {
        cout << 0;
        return 0;
    }

    ModFactorial f(m + 1);
    cout << f.getCombination(m, mx);
}