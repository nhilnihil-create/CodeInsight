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

int main()
{   
    int n;
    cin >> n;
    vi a(n+1);
    rep(i, n) cin >> a[i+1];
    vi b(n+1);
    for(int i = n; i >= 1; i--) {
        int sum = 0;
        for(int j = i+i; j <= n; j+=i) {
            sum ^= b[j];
        }
        b[i] = sum^a[i];
    }
    vi ans;
    for(int i = 1; i <= n; i++) {
        if(b[i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }

    return 0;
}
