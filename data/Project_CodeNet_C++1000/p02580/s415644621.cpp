#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int main() {
    int h , w , n;
    cin >> h >> w >> n;
    vector<int> a(h), b(w);
    set<pair<int , int>> s;
    rep(i,n) {
        int c , d;
        cin >> c >> d;
        --c;
        --d;
        a[c]++;
        b[d]++;
        s.emplace(c , d);
    }
    int e = 0, f = 0;
    for(int i = 0; i < h; i++){
        e = max(e, a[i]);
    }
    for(int i = 0; i < w; i++){
        f = max(f, b[i]);
    }
    vector<int> g, k;
    for(int i = 0; i < h; i++){
        if (e == a[i]){
            g.push_back(i);
        }
    }
    for(int i = 0; i < w; i++){
        if (f == b[i]){
            k.push_back(i);
        }
    }
    int ans = e + f;
    for(int i : g) for (int j : k) {
        if(s.count(pair<int , int>(i , j))){
            continue;
        }
        cout << ans << endl;
        return 0;
    }
    --ans;
    cout << ans << endl;
    return 0;
}
