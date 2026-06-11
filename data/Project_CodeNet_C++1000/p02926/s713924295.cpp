#include <algorithm>
#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

bool comparg(const P& p1, const P& p2){
    if(p1.first >= 0 && p2.first < 0) return true;
    if(p1.first < 0 && p2.first >= 0) return false;
    if(p1.first == 0 && p2.first == 0){
        if(p1.second < 0 && p2.second > 0) return true;
        if(p1.second > 0 && p2.second < 0) return false;
    }
    if(p1.second * p2.first == p1.first * p2.second) return p1.first + p1.second < p2.first + p2.second;
    return p1.second * p2.first < p1.first * p2.second;
}

int main()
{
    int n;
    cin >> n;
    ll x[103], y[103];
    P p[103];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        p[i] = P(x[i], y[i]);
    }
    ll ans = 0;
    sort(p, p + n, comparg);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ll xsum = 0, ysum = 0;
            for(int k = 0; k <= j; k++){
                xsum += p[(i + k) % n].first;
                ysum += p[(i + k) % n].second;
            }
            ans = max(ans, xsum * xsum + ysum * ysum);
        }
    }
    cout << fixed << setprecision(15) << sqrt(ans) << endl;
}