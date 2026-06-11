#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll g(ll n) {return n * (n+1) / 2;}


int main()
{   
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vll a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    vll sa(n+1), sb(m+1);
    rep(i, n) sa[i+1] = sa[i] + a[i];
    rep(i, m) sb[i+1] = sb[i] + b[i];

    int ans = 0;
    rep(i, n+1) {
        if(sa[i] > k) continue;
        auto itr = upper_bound(all(sb), k-sa[i]);
        int x = itr - sb.begin(); --x;
        ans = max(ans, i+x);
        //cout << i << " " << k-sa[i] << " " << x << endl;
    }

    cout << ans << endl;
    

    return 0;
}
