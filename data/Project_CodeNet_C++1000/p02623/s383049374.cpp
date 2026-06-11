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

int main()
{   
    int n, m, k;
    cin >> n >> m >> k;
    vll a(n+1), b(m+1);
    rep(i, n) {
        int x;
        cin >> x;
        a[i+1]=a[i]+x;
    }
    rep(i, m) {
        int x;
        cin >> x;
        b[i+1]=b[i]+x;
    }
    
    int ans = 0;
    rep(i, n+1) {
        if(a[i]>k) continue;
        auto itr = upper_bound(all(b), k-a[i]);
        int t = (itr-b.begin())-1;
        ans = max(ans, i + t);
    }

    cout << ans << endl;

    return 0;
}
