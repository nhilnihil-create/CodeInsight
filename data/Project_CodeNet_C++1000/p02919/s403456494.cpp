#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)


template<class T> class SegTree
{
    private:
        int _n;
        int _d;

        template<class U> class SNode
        {
            public:
                U _min;
                U _max;
                U _sum;
                bool _used;

                SNode()
                {
                    _min = 0;
                    _max = 0;
                    _sum = 0;
                    _used = false;
                }

                SNode(SNode<U> &t)
                {
                    copy(t);
                }

                void set(SNode<U> &t)
                {
                    _min = t._min;
                    _max = t._max;
                    _sum = t._sum;
                    _used = t._used;
                }


                void set(U v)
                {
                    _min = v;
                    _max = v;
                    _sum = v;
                    _used = true;
                }
        };

        SNode<T>* nodes;

        int dindex(int d)
        {
            return (1 << d);
        }

        void evalnode(int index)
        {
            if( index < 1 ) return;
            if( nodes[index * 2]._used && nodes[index * 2 + 1]._used )
            {
                nodes[index]._min = min(nodes[index * 2]._min, nodes[index * 2 + 1]._min);
                nodes[index]._max = max(nodes[index * 2]._max, nodes[index * 2 + 1]._max);
                nodes[index]._sum = nodes[index * 2]._sum + nodes[index * 2 + 1]._sum;
                nodes[index]._used = true;
            }
            else if( nodes[index * 2]._used )
            {
                nodes[index].set(nodes[index * 2]);
            }
            else if( nodes[index * 2 + 1]._used )
            {
                nodes[index].set(nodes[index * 2 + 1]);
            }

            if( nodes[index]._used ) evalnode(index / 2);
        }

        // 対象ノードが範囲に含まれるか　-1: 含まれない、　0:部分的に含まれる、1:完全に含む
        int check(int l, int r, int index, int d)
        {
            int i = index - (1 << d);
            int k = ( 1 << ( _d - d - 1) );
            if( r <= i * k || l >= (i + 1) * k ) return -1;
            if( l <= i * k && r >= (i + 1) * k ) return 1;
            return 0;
        }

        T getminsub(int l, int r, int index, int d)
        {
            if( d == _d - 1 ) nodes[index]._min;
            if( check(l, r, index, d) == 1 ) return nodes[index]._min;
            if( check(l, r, index * 2, d + 1) == -1 ) return getminsub(l, r, index * 2 + 1, d + 1);
            if( check(l, r, index * 2 + 1, d + 1) == -1 ) return getminsub(l, r, index * 2, d + 1);
            return min(getminsub(l, r, index * 2 + 1, d + 1), getminsub(l, r, index * 2, d + 1));
        }

        T getmaxsub(int l, int r, int index, int d)
        {
            if( d == _d - 1 ) nodes[index]._max;
            if( check(l, r, index, d) == 1 ) return nodes[index]._max;
            if( check(l, r, index * 2, d + 1) == -1 ) return getmaxsub(l, r, index * 2 + 1, d + 1);
            if( check(l, r, index * 2 + 1, d + 1) == -1 ) return getmaxsub(l, r, index * 2, d + 1);
            return max(getmaxsub(l, r, index * 2 + 1, d + 1), getmaxsub(l, r, index * 2, d + 1));
        }

        T getsumsub(int l, int r, int index, int d)
        {
            if( d == _d - 1 ) nodes[index]._sum;
            if( check(l, r, index, d) == 1 ) return nodes[index]._sum;
            if( check(l, r, index * 2, d + 1) == -1 ) return getsumsub(l, r, index * 2 + 1, d + 1);
            if( check(l, r, index * 2 + 1, d + 1) == -1 ) return getsumsub(l, r, index * 2, d + 1);
            return getsumsub(l, r, index * 2 + 1, d + 1) + getsumsub(l, r, index * 2, d + 1);
        }


    public:
        SegTree(int n)
        {
            _n = n;
            _d = 1;
            int bit = 1;
            while( bit < _n )
            {
                bit *= 2;
                _d++;
            }
            nodes = new SNode<T>[bit * 2];
        }

        ~SegTree()
        {
            delete nodes;
        }

        void set(int i, T value)
        {
            int index = dindex(_d - 1) + i;
            nodes[index].set(value);
            evalnode(index / 2);
        }

        // l <= i < r
        T getmin(int l, int r)
        {
            return getminsub(l, r, 1, 0);
        }

        T getmax(int l, int r)
        {
            return getmaxsub(l, r, 1, 0);
        }

        T getsum(int l, int r)
        {
            return getsumsub(l, r, 1, 0);
        }
};

int findbiggerleft(int target, int pos, SegTree<int> &st)
{
    int l = -1;
    int r = pos;
    while( l + 1 < r )
    {
        int m = (l + r) / 2;
        if( st.getmax(m, pos) > target )
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    return l;
}

int findbiggerright(int target, int pos, int n, SegTree<int> &st)
{
    int l = pos;
    int r = n;
    while( l + 1 < r )
    {
        int m = r - (r - l) / 2;
        if( st.getmax(pos + 1, m + 1) > target )
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    return r;
}


int main()
{
    int n; cin >> n;
    vector<int> p(n);
    SegTree<int> st(n);
    rep(i, n)
    {
        cin >> p[i];
        st.set(i, p[i]);
    }
    _LL ans = 0;
    rep(i, n)
    {
        _LL l1 = findbiggerleft(p[i], i, st);
        _LL l2 = -1;
        if( l1 > 0 ) l2 = findbiggerleft(p[i], l1, st);
        _LL r1 = findbiggerright(p[i], i, n, st);
        _LL r2 = n;
        if( r1 < n - 1 ) r2 = findbiggerright(p[i], r1, n, st);
        ans += ((i - l1) * (r2 - r1) + (r1 - i) * (l1 - l2)) * (_LL) p[i];
    }
    cout << ans << endl;
    return 0;    
}