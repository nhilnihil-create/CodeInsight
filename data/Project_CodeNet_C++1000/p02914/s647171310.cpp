#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

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

        void print()
        {
            for( int j = 0; j < _h; j++ )
            {
                for( int i = 0; i < _w; i++ )
                {
                    cout << (*this)[i][j] << " ";
                }
                cout << endl;
            }
        }
};

void bithakidasi(_LL *a, int n, int keta)
{
    int r = 0;
    for(int k = keta - 1; k >= 0; k-- )
    {
        if( r >= n ) return;
        int tr = r;
        for(tr = r; tr < n; tr++)
        {
            if( (a[tr] & (1LL << k)) == 0 ) continue;
            if( tr != r ) swap(a[r], a[tr]);
            break;
        }

        if( (a[r] & (1LL << k)) == 0 ) continue;

        for(int i = 1; i < n; i++)
        {
            if( i == r ) continue;
            if( (a[i] & (1LL << k)) != 0 ) 
            a[i] ^= a[r];
        }

        if( (a[0] & (1LL << k)) == 0 ) a[0] ^= a[r];
        r++;
    }
}

int main()
{
    _LL n = 0;
    cin >> n;
    MultiArray2<char> a(n, 60);
    char sum[60];
    bool hasm[60];
    rep(j, 60) sum[j] = 0;
    rep(j, 60) hasm[j] = false;
    rep(i, n)
    {
        _LL t;
        cin >> t;
        rep(j, 60)
        {
            a[i][j] = ((t & (1LL << j)) == 0) ? 0 : 1;
            if(a[i][j]) hasm[j] = true;
            sum[j] = sum[j] ^ a[i][j];
        }
    }


    _LL ans = 0;
    _LL leftrank = n;

    int bit[60];
    int index = 0;
    _LL *ta = new _LL[n];
    rep(i, n) ta[i] = 0;

    int *x = new int[n];

    rep(ij, 60)
    {
        int j = 60 - ij - 1;
        if( !hasm[j] ) continue;
        if( sum[j] == 1 )
        {
            ans += (1LL << j);
        }
        else
        {
            rep(i, n) ta[i] = (ta[i] << 1) + a[i][j];
            bit[index++] = j;
        }
    }
//    rep(j, index) cout << ta[j] << endl;
    bithakidasi(ta, n, index);
//    cout << endl;
//    rep(j, index) cout << ta[j] << endl;
    rep(j, index)
    {
        if( ta[0] & (1LL << j) )
        {
            ans += 2 * (1LL << bit[index - 1 - j]);
        }
    }

    cout << ans << endl;
    return 0;    
}