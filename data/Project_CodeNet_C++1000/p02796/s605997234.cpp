#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;

signed main(){
    int n;
    cin >> n;
    vector<P> robots(n);
    rep(i, n){
        int x, l;
        cin >> x >> l;
        robots[i] = make_pair(x+l, x-l);
    }
    sort(robots.begin(), robots.end());

    int ans = 0, now_x = -100000000;

    rep(i, n){
        /* printf("%d, %d\n", robots[i].first, now_x); */
        if(now_x <= robots[i].second){
            ans++;
            now_x = robots[i].first;
        }
    }
    cout << ans << endl;
}