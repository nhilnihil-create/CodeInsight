#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, x, n) for (ll i = x; i < (ll)(n); i++)
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, ans = 0;
    cin >> n;

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];

    rep(i, n) cin >> b[i];

    priority_queue<ll> q;
    for(int i=0;i < n;i++)
    {
        if (b[(i + 1) % n] < b[i] && b[i] > b[(i - 1 + n) % n])
        {
            q.push(i);
        }
    }
    

    while(!q.empty())
    {
        ll ind=q.top();
        q.pop();

        if (b[ind] <= a[ind])
            continue;

        ll ng = 0, ok = INF,fr=b[(ind + 1) % n],ba=b[(ind - 1 + n) % n];
        while (abs(ng - ok) > 1)
        {
            ll mid = (ok + ng) / 2, B = b.at(ind) - (mid) * (fr + ba);

            if (B>a[ind] && (fr < B && B > ba))
            {
                ng = mid;
            }
            else
            {
                ok = mid;
            }
        }

        b.at(ind) -= ok * (fr+ba);

        if (b[ind] < a[ind])
            break;

        ans += ok;

        ind+=n-1;
        ind%=n;
        if (b[(ind + 1) % n] < b[ind] && b[ind] > b[(ind - 1 + n) % n])
        {
            q.push(ind);
        }

        ind+=2;
        ind%=n;
        if (b[(ind + 1) % n] < b[ind] && b[ind] > b[(ind - 1 + n) % n])
        {
            q.push(ind);
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cout << -1 << endl;
            return 0;
        }

    }

    cout << ans << endl;
}