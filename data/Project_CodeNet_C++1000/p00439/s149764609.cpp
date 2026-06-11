#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> plli;
typedef pair<int,pii> pipii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()

const ll mod = 1e9 + 7;
const ll INF = 1<<30;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = 3.141592653589793;

int n, k;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    while (n != 0) {
        int a[n + 1] = {};
        rep(i, n) cin >> a[i];
        rep(i, n) a[i + 1] += a[i];
        int ans = -1e12;
        rep(i, n - k) ans = max(ans, a[i + k] - a[i]);
        ans = max(ans, a[k - 1]);
        cout << ans << endl;
        cin >> n >> k;
    }

}