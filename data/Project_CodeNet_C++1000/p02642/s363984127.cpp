#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
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

int MAX = 1000010;

int main()
{   
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi cnt(MAX);
    for(auto x : a) {
        if(cnt[x] >= 2) continue;
        for(int i = x; i <= MAX; i += x) {
            cnt[i]++;
        }
    }

    //cout << cnt[5] << endl;

    int ans = 0;
    for(auto x : a) {
        if(cnt[x] >= 2) continue;
        ans++;
    }

    cout << ans << endl;

    return 0;
}
