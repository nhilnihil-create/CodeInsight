#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define mod 1e9+7
#define INF 1 << 30
#define MAX (1 << 20)
#define NINF (-(1 << 30))
#define Point pair<int, int>
#define triplet pair<pair<int, int>, int>

const int maxs = 2000;
ll fact[maxs];

ll power(ll base, ll p, ll pr){
    ll ans = 1;

    if(base == 1)
        return 1;

    if(base == 0)
        return 0;

    while(p){
        if(p&1)
            ans = (ans*base)%pr;

        base = (base*base)%pr;
        p >>= 1;
    }

    return ans;
}

ll invMod(ll num) {
    return power(num, mod-2, mod);
}

ll nCk(ll n, ll k) {
    return (fact[n] * invMod((fact[n-k] * fact[k]) % ( (ll) mod))) % ( (ll) mod);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<Point> points(n);

    while (n--) {
        cin >> points[n].first >> points[n].second;
    }

    sort(points.begin(), points.end(), [](Point p1, Point p2){return (p1.first + p1.second) < (p2.first + p2.second);});

    ll ans = abs((points[0].first + points[0].second) - (points.back().first + points.back().second));

    //cout << "max: " << (points[0].first + points[0].second) << endl;
    
    sort(points.begin(), points.end(), [](Point p1, Point p2){return (p1.first - p1.second) < (p2.first - p2.second);});

    ll tmp = abs((points[0].first - points[0].second) - (points.back().first - points.back().second));

    cout << max(tmp, ans) << endl;
    return 0;
}