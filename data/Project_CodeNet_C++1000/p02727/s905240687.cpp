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
    sort(all(ncolor));
    reverse(all(red));
    reverse(all(green));
    reverse(all(ncolor));


    priority_queue<ll, vll, greater<ll>> reds;
    ll sumred = 0;
    priority_queue<ll, vll, greater<ll>> greens;
    ll sumgreen = 0;

    for(int i = 0; i < x; i++) {
        sumred += red[i];
        reds.push(red[i]);
    }
    for(int i = 0; i < y; i++) {
        sumgreen += green[i];
        greens.push(green[i]);
    }

    for(int i = 0; i < c; i++) {
        ll lowestred = reds.top();
        ll lowestgreen = greens.top();
        ll val = ncolor[i];
        ll diff1 = val - lowestred;
        ll diff2 = val - lowestgreen;
        if(diff1 <= 0 && diff2 <= 0) break;
        else if(diff1 <= 0 && diff2 > 0) {
            greens.pop();
            greens.push(val);
            sumgreen += diff2;
        } else if(diff1 > 0 && diff2 <= 0) {
            reds.pop();
            reds.push(val);
            sumred += diff1;
        } else {
            if(diff1 > diff2) {
                reds.pop();
                reds.push(val);
                sumred += diff1;
            } else {
                greens.pop();
                greens.push(val);
                sumgreen += diff2;
            }
        }
    }
    cout << sumgreen + sumred << endl;
    return 0;
}
