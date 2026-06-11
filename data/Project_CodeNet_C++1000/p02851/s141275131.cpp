#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <map>

#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define pf push_front

using namespace std;
using ll=long long;
using ld=long double;

const int maxn = 1e6 +2;
const int base = 31;
const int mod = 1e9 +7;

template<class T>
void read(T &x)
{
    register ll c;
    T neg = 1;
    x = (T)0;
    while ((c = getchar()) <= 47 || c >= 58)
        if(c == '-') neg = -1;
    for (; (c > 47 && c < 58); c = getchar())
    {
        x = (x << 3) + (x << 1) + (T)(c - 48);
    }
    x *= neg;
}

int n, k;
ll pre = 0;
map<int, ll> dem;
ll gt[maxn];
int main()
{
    cin >> n >> k;
    ll tong = 0;
    dem.insert({0, 1});
    gt[0] = 0;
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        x--;
        pre += x;
        pre %= k;
        gt[i+1] = pre;
        if (i >= k -1)
        {
            dem[gt[i- k + 1]]--;
        }
        if (dem.count(pre))
        {
            tong += dem[pre];
            dem[pre]++;
        }
        else
        {
            dem.insert({pre, 1});
        }
    }
    cout << tong;
}
