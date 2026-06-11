#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

pair<int, int> p[N];
pair<ll, int> pos_pos[N], pos_neg[N], neg_pos[N], neg_neg[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
        pos_pos[i] = {x + y, i};
        pos_neg[i] = {x - y, i};
        neg_pos[i] = {-x + y, i};
        neg_neg[i] = {-x -y, i};
    }
    sort(pos_pos, pos_pos + n);
    sort(pos_neg, pos_neg + n);
    sort(neg_pos, neg_pos + n);
    sort(neg_neg, neg_neg + n);

    int i = n - 1;

    if(neg_neg[n - 1].second == pos_pos[i].second) {
        ans = max(ans, neg_neg[n - 2].first + pos_pos[i].first);
    }
    else ans = max(ans, neg_neg[n - 1].first + pos_pos[i].first);

    if(neg_pos[n - 1].second == pos_neg[i].second) {
        ans = max(ans, neg_pos[n - 2].first + pos_neg[i].first);
    }
    else ans = max(ans, neg_pos[n - 1].first + pos_neg[i].first);

    if(pos_pos[n - 1].second == neg_neg[i].first)
        ans = max(ans, pos_pos[n- 2].first + neg_neg[i].first);

    else ans = max(ans, pos_pos[n - 1].first + neg_neg[i].first);

    if(pos_neg[n - 1].second == neg_pos[i].second) {
        ans = max(ans, pos_neg[n - 2].first + neg_pos[i].first);
    }
    else ans = max(ans, pos_neg[n - 1].first + neg_pos[i].first);
    cout << ans;

    return 0;
}
