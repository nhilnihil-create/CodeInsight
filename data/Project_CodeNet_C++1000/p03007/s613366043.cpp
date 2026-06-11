#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;

int main(){
    
    int N;
    cin >> N;

    vector<ll> a(N);
    rep(i, N)cin >> a[i];
    sort(all(a));

    vector<int> sign(N);
    rep(i, N){
        if(a[i] >= 0)sign[i] = 1;
        else sign[i] = -1;
    }
    if(a[0] > 0)sign[0] = -1;
    if(a[N - 1] < 0)sign[N - 1] = 1;

    ll ans = 0;
    int pcnt = 0, ncnt = 0;
    rep(i, N)ans += a[i] * sign[i];
    cout << ans << endl;

    ll now = a[N - 1] - a[0];
    vector<pair<int, int>> vec(N - 1);
    vec[0].first = a[N - 1];
    vec[0].second = a[0];

    vector<bool> swaps(N - 1, false);
    for(int i = 1; i < N - 1; i++){
        if(sign[i] == 1){
            swaps[i - 1] = true;
            vec[i].first = a[i];
            vec[i].second = -now;
            now += a[i];
        } else {
            vec[i].first = now;
            vec[i].second = a[i];
            now -= a[i];
        }
    }

    rep(i, N - 1){
        if(swaps[i])swap(vec[i].first, vec[i].second);
        cout << vec[i].first << ' ' << vec[i].second << endl;
    }

}