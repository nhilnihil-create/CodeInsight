
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

struct Point { LL x,y; };

bool cmp(const Point& a, const Point& b)
{
    return atan2(a.y,a.x) < atan2(b.y,b.x);
}

int main()
{
#ifdef foo_
    freopen("foo", "rt", stdin);
#endif
    int n;
    while (cin >> n) {
        vector<Point> A(n);
        FOR(i,0,n)
            cin >> A[i].x >> A[i].y;
        sort(ALL(A),cmp);
        FOR(i,0,n)
            A.push_back(A[i]);
        LL ans = 0;
        FOR(i,0,2*n) {
            LL x = 0, y = 0;
            FOR(j,i,min(2*n,i+n)) {
                x += A[j].x;
                y += A[j].y;
                ans = max(ans, x*x + y*y);
            }
        }
        cout.precision(12); cout << fixed << sqrt(ans) << endl;
    }
    return 0;
}
