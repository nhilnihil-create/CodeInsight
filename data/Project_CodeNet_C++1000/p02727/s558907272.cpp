#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// head

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    ll sum = 0;

    vll red(a);
    vll green(b);
    vll ncolor(c);
    rep(i,0,a) cin >> red[i];
    rep(i,0,b) cin >> green[i];
    rep(i,0,c) cin >> ncolor[i];

    sort(all(red));
    sort(all(green));
    reverse(all(red));
    reverse(all(green));
    for(int i = 0; i < x; i++) {
        ncolor.pb(red[i]);
    }
    for(int i = 0; i < y; i++) {
        ncolor.pb(green[i]);
    }
    sort(all(ncolor));
    reverse(all(ncolor));
    for(int i = 0; i < x + y; i++) {
        sum += ncolor[i];
    }
    cout << sum << endl;

    return 0;
}
