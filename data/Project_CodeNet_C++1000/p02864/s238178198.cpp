#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long
#define rep(i, n) for(_LL i = 0; i < (_LL)(n); i++)


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


#define INF (1UL << 60)

int main()
{
    _LL n, k;
    cin >> n >> k;
    _LL *h = new _LL[n];

    MultiArray2<_LL> dp(n, k + 1, true);
    rep(i, n) cin >> h[i];

    if( n == k )
    {
        cout << 0 << endl;
        return 0;
    }
    rep(i, n)
    {
        if( i == 0 )
        {
            rep(j, k + 1) dp[i][j] = INF;
            dp[i][0] = h[i];
            continue;
        }
        rep(j, k + 1)
        {
            dp[i][j] = INF;
            rep(m, j + 1)
            {
                if( i - 1 - m < 0 )
                {
                    dp[i][j] = min(dp[i][j], h[i]);
                    break;
                }
                _LL tmp = dp[i - 1 - m][j - m];
                if( h[i] > h[i - 1 - m] ) tmp += h[i] - h[i - 1 - m];
                dp[i][j] = min(dp[i][j], tmp);
            }
        }
    }

    _LL ans = INF;
    
    rep(m, k + 1)
    {
        ans = min(ans, dp[n - 1 - m][k - m]);
    }
//    rep(i, n)
//        rep(j, k + 1) cout << i << "," << j << "," << ":" << dp[i][j] << endl;
    cout << ans << endl;
}