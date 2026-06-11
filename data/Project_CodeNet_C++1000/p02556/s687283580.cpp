#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;



int main(){
    ll n;
    cin >> n;
    vector<pair<int,int>> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }

    ll ans = 0;
    vector<ll> x2(n), y2(n);
    for(int i = 0; i < n; i++){
        x2[i] = p[i].first+p[i].second;
        y2[i] = p[i].first-p[i].second;
    }
    sort(x2.begin(), x2.end());
    sort(y2.begin(), y2.end());

    ans = max(x2[n-1]-x2[0], y2[n-1]-y2[0]);

    cout << ans << endl;

    return 0;
}