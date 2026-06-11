#include <bits/stdc++.h>
#define fname "D"
#define cerr if(false)cerr
#define bug(x) cerr << (#x) << " = " << (x) << endl
#define ll long long
#define REP0(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define REP1(i, n) for(int i = 1, _n = (n); i <= _n; ++i)
#define REPB0(i, n) for(int i = (n) - 1; i >= 0; --i)
#define REPB1(i, n) for(int i = (n); i > 0; --i)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORB(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define ARR0(a, n) {cerr <<(#a)<< ": ["; REP0(i, n) cerr<< ' ' << a[i] <<','; cerr<<']'<<endl;}
#define ARR1(a, n) {cerr <<(#a)<< ": ["; REP1(i, n) cerr<< ' ' << a[i] <<','; cerr<<']'<<endl;}
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define LB lower_bound
#define UB upper_bound
#define X first
#define Y second

using namespace std;
template<typename T, typename V>
inline void bugp(const pair<T, V> &x) {cerr << '{' << x.X << ", " << x.Y << '}' << endl;}
template<typename T, typename U, typename V>
inline void bugpp(const pair<T, pair<U, V> > &x) {cerr << '{' << x.X << ", {" << x.Y.X << ", " << x.Y.Y << "}}" << endl;}
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, int> li;
typedef pair<ll, ii> lii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 5005;
int c[N], p[N], leng[N];
ll d[N];

int main()
{
    
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k;
    cin >> n >> k;
    REP1(i, n) cin >> p[i];
    REP1(i, n) cin >> c[i];
    int id, prev, len, cnt, s;
    ll w, ans = LLONG_MIN, val;
    REP1(i, n) {
        bug(i);
        memset(leng, 0, sizeof leng);
        d[i] = cnt = 0;
        id = p[i];
        prev = i;
        while(!leng[id] && id != i) {
            leng[id] = leng[prev] + 1;
            d[id] = d[prev] + c[id];
            bug(id); bug(leng[id]); bug(d[id]);
            ++cnt;
            if(cnt <= k) ans = max(ans, d[id]);
            else break;
            prev = id;
            id = p[id];
        }
        if(cnt >= k) continue;
        bug(d[prev]); bug(c[id]);
        ans = max(ans, d[prev] + c[id]);
        ++cnt;
        w = d[prev] + c[id] - d[id];
        len = leng[prev] + 1 - leng[id];
        bug(w); bug(len);
        if(w > 0 && (k - cnt)) {
            if((k - cnt) % len == 0) {
                val = ((k - cnt) / len - 1) * w + d[prev] + c[id];
                ans = max(ans, val);
                s = id;
                do {
                    s = p[s];
                    ans = max(ans, val + c[s]);
                    val += c[s];
                } while(s != id);
            }
            else {
                val = (k - cnt) / len * w + d[prev] + c[id];
                ans = max(ans, val);
                s = p[id];
                cnt = (k - cnt) % len;
                while(cnt) {
                    --cnt;
                    ans = max(ans, val + c[s]);
                    val += c[s];
                    s = p[s];
                }
            }
        }
    }
    cout << ans;
	return 0;
}
