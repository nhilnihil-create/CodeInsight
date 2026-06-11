#include <bits/stdc++.h>
using namespace std ;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll ;
typedef unsigned long long ull ;
typedef long double ld ;

const ll MOD = 1E9 + 7, INF = 2E18 + 5 ;
const double PI = 2 * acos(0.0) ;
const long double EPS = 1.0E-14 ;

map <ll, ll> mpRow, mpCol ;
pair <ll, ll> pt[300005] ;

int main()
{
    ll r, c, m, ans = 0, val, ind = 0, check = 0 ;
    cin >> r >> c >> m ;
    for (int i = 0; i < m; i++) {
        scanf("%lld %lld", &pt[i].first, &pt[i].second) ;
        mpRow[pt[i].first]++, mpCol[pt[i].second]++ ;
    }

    for (auto it = mpRow.begin(); it != mpRow.end(); it++) {
        if (it->second >= ind) {
            ind = it->second ;
            val = it->first ;
        }
    }

    for (auto it = mpCol.begin(); it != mpCol.end(); it++) {
        if (it->second >= ind) {
            ind = it->second ;
            val = it->first ;
            check = 1 ;
        }
    }
    ans += ind ;

    if (!check) {
        for (int i = 0; i < m; i++) {
            if (pt[i].first == val) {
                mpCol[pt[i].second]-- ;
            }
        }
        ind = 0 ;
        for (auto it = mpCol.begin(); it != mpCol.end(); it++) {
            ind = max(ind, it->second) ;
        }
        ans += ind ;
    }
    else {
        for (int i = 0; i < m; i++) {
            if (pt[i].second == val) {
                mpRow[pt[i].first]-- ;
            }
        }
        ind = 0 ;
        for (auto it = mpRow.begin(); it != mpRow.end(); it++) {
            ind = max(ind, it->second) ;
        }
        ans += ind ;
    }

    cout << ans ;

    return 0 ;
}
