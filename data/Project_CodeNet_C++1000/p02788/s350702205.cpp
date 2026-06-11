
#include <bits/stdc++.h>

using namespace std;

/* g++ -g -fsanitize=address -lasan -std=c++11 -Dfoo_ */

/* freopen("input.txt", "rt", stdin); */
/* freopen("output.txt", "wt", stdout); */

#define ALL(c)          (c).begin(), (c).end()
#define ALLR(c)         (c).rbegin(), (c).rend()
#define FOR(i,a,b)      for (int i=(a); i < (b); ++i)
#define FORR(i,a,b)     for (int i=(a); i > (b); --i)
#define FOR_ALL(i,c)    for (__typeof((c).begin()) i=(c).begin();   \
                             i != (c).end(); ++i)
#define FOR_ALLR(i,c)   for (__typeof((c).rbegin()) i=(c).rbegin(); \
                             i != (c).rend(); ++i)
#define SZ(array)       (sizeof(array)/sizeof(array[0]))
#define lc(x)           (x<<1)     /* 2*x */
#define rc(x)           (x<<1 | 1) /* 2*x+1 */
#define lowbit(x)       (x & (-x)) /* 0b10100 -> 0b100 */

typedef long long       LL;
typedef map<int,int>    MII;
typedef pair<int,int>   PII;
typedef set<int>        SI;
typedef vector<bool>    VB;
typedef vector<double>  VD;
typedef vector<int>     VI;
typedef vector<string>  VS;

/* check if a key is in container C */
template <class C>
inline bool in_(const typename C::key_type& k, const C& A)
{ return A.find(k) != A.end(); }
inline bool in_(const string& s, const string& S)
{ return S.find(s) != string::npos; }

/*
 * Because the first one has to be taken out, we can put the bomb at
 * the place where it can reach to x[i]+2*d. We need a segtree to take
 * care of range add operation. Alternatively we can just use a prefix
 * sum.
 *
 *   i           j      Let's say we drop a bomb that covers [i,j), we
 * -[x]-[x]-[x]-[x]-    can add v at i, and add -v at j. This way, when
 *   |           |      we move to i+1, prefix sum carries +v, but
 *  +v          -v      we reach to j, prefix sum cancels out w/ -v.
 */

int main()
{
#ifdef foo_
    freopen("foo", "rt", stdin);
#endif
    ios::sync_with_stdio(false);
    int n,d,a;
    while (cin >> n >> d >> a) {
        vector<PII> A(n+1);
        FOR(i,1,n+1)
            cin >> A[i].first >> A[i].second;
        sort(ALL(A));
        vector<LL> x(n+1), h(n+1);
        FOR(i,1,n+1)
            x[i] = A[i].first, h[i] = A[i].second;
        LL ans = 0; vector<LL> sum(n+2);
        FOR(i,1,n+1) {
            sum[i] += sum[i-1];
            h[i  ] -= sum[i]*a;
            if (h[i] > 0) {
                const int j = upper_bound(ALL(x), x[i]+2*d) - x.begin();
                const int c = (h[i]+a-1) / a;
                sum[i] += c;
                sum[j] -= c;
                ans += c;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
