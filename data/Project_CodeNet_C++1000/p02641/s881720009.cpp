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
    int x, n;
    cin >> x >> n;
    set<int> s;
    rep(i, n) {
        int a;
        cin >> a;
        s.insert(a);
    }
    int mi = 114514;
    int ans = 114514;
    rep(i, 102) {
        if(s.find(i) != s.end()) continue;
        if(mi > abs(x-i)) {
            mi = abs(x-i);
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}
