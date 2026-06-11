#include<bits/stdc++.h>
#define GO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
const int N = 16;
const int M = 1e3 + 5;
const int Mod = 998244353;

struct Base
{
    int m;
    vector <ll> A;

    Base(int m = 0) : m(m)
    {
        A.assign(max(m, 1), 0);
    }

    void insert(ll x)
    {
        for (ll i = m - 1; ~i; --i)
        {
            if (x & (1LL << i))
            {
                if (A[i])
                {
                    x ^= A[i];
                }

                else
                {
                    A[i] = x;
                    break;
                }
            }
        }
    }

    vector <ll> Get()
    {
        vector <ll> Res;

        for (int i = 0; i < m; i++)
            if (A[i])
                Res.push_back(A[i]);

        return Res;
    }
};

int main()
{
    GO;
    int n;
    cin >> n;
    ll XOR = 0;
    vec a(n);
    for (auto& i : a)
        cin >> i, XOR ^= i;
    ll sum = XOR;
    for (auto& i : a)
        i &= ~XOR;
    Base b(60);
    for (auto i : a)
        b.insert(i);
    XOR = (1LL << 60) - 1 - XOR;
    ll temp = XOR;
    for(int i=59;i>=0;i--)
        if (XOR & 1LL << i)
        {
            if (temp & 1LL << i)
                temp ^= b.A[i];
            if (~temp & 1LL << i)
                sum += 2LL << i;
        }
    cout << sum<< endl;
    return 0;
}