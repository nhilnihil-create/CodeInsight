// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
const ll infll = 1e18 + 9;
const int infint = 1e9 + 7;
const int MAXN = 2e5 + 7;
const double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;
const long double e = 2.71828182845904523536028747135266;
inline ll read()
{
    ll kr = 1, xs = 0;
    char ls;
    ls = getchar();
    while (!isdigit(ls))
    {
        if (!(ls ^ 45))
            kr = -1;
        ls = getchar();
    }
    while (isdigit(ls))
    {
        xs = (xs << 1) + (xs << 3) + (ls ^ 48);
        ls = getchar();
    }
    return xs * kr;
}
// inline __int128 read128()
// {
//     __int128 kr=1,xs=0;char ls;ls=getchar();
//     while(!isdigit(ls)){
//         if(!(ls^45)) kr=-1;ls=getchar();
//     }
//     while(isdigit(ls)){
//         xs=(xs<<1)+(xs<<3)+(ls^48);ls=getchar();
//     }
//     return xs*kr;
// }
inline ull readull()
{
    ull xs = 0;
    char ls;
    ls = getchar();
    while (!isdigit(ls))
        ls = getchar();
    while (isdigit(ls))
    {
        xs = (xs << 1) + (xs << 3) + (ls ^ 48);
        ls = getchar();
    }
    return xs;
}
inline void writeull(ull x)
{
    if (x < 0)
    {
        x *= -1;
        putchar('-');
    }
    if (x >= 10)
        writeull(x / 10);
    putchar('0' + x % 10);
}
inline void write(ll x)
{
    if (x < 0)
    {
        x *= -1;
        putchar('-');
    }
    if (x >= 10)
        write(x / 10);
    putchar('0' + x % 10);
}
// inline void write(__int128 x){
//     if(x<0){x*=-1;putchar('-');}
//     if(x>=10) write(x/10);
//     putchar('0'+x%10);
// }
///////////////////////////////////////////////////////////////////////////////////////
ll a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // t = read();
    while (t--)
    {
        int n = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
        }
        ll ans = 0;
        for (int i = 2; i <= n; i++)
        {
            if (a[i] < a[i - 1])
            {
                ans += (a[i - 1] - a[i]);
                a[i] = a[i - 1];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
