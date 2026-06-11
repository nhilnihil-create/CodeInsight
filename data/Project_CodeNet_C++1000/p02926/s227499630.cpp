#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <pair <int, int> > a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i.first >> i.second;
    sort(a.begin(), a.end(), [&](pair <int, int> &l, pair <int, int> &r){
        return atan2(l.second, l.first) < atan2(r.second, r.first);
    });
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        int x = 0, y = 0;
        for(int j = 0 ; j < n ; j++){
            x += a[(i + j) % n].first;
            y += a[(i + j) % n].second;
            ans = max(ans, 1LL * x * x + 1LL * y * y);
        }
    }
    cout << setprecision(12) << sqrtl(ans) << endl;
}
