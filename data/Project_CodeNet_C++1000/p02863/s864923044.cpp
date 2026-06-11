#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define _LL long long
#define rep(i, n) for(_LL i = 0; i < (_LL)(n); i++)
// 二次元配列

template <class T> class MultiArray2
{
    public:
        T* _a;
        int _w;
        int _h;
        MultiArray2(int w, int h, bool clr = false)
        {
            _w = w; _h = h;
            _a = new T[_w * _h];
            if(clr) memzero();
        }

        void memzero()
        {
            memset(_a, 0, _w * _h * sizeof(T));
        }

        ~MultiArray2()
        {
            delete _a;
        }

        T* operator[](int i)
        {
            return _a + (i * _h);
        }
};

int main()
{
    int n, t;
    cin >> n >> t;
    pair<int,int> *f = new pair<int,int>[n];
    rep(i, n)
    {
        cin >> f[i].first >> f[i].second;
        f[i].first *= -1;
    }
    sort(f, f + n);
    MultiArray2<int> dp(n, t, true);
    rep(i, n)
    {
        if( i == 0 )
        {
            rep(k, t) dp[i][k] = f[i].second;
            continue;
        }
        // 注文にかかる時間を降順にならべて、i番目までから選んだ時
        rep(k, t)
        {
            if( k == 0 )
            {
                dp[i][k] = max(f[i].second, dp[i-1][k]);
            }
            else if( k >= -f[i].first )
            {
                dp[i][k] = max(max(dp[i-1][k], dp[i-1][k + f[i].first] + f[i].second), dp[i][k-1]);
            }
            else
            {
                dp[i][k] = max(dp[i-1][k], dp[i][k-1]);
            }
        }
    }
//    rep(i, n)
//        rep(k, t) cout << "(" << i << "," << k << ") = " << dp[i][k] << endl;
    cout << dp[n-1][t-1] << endl;
}