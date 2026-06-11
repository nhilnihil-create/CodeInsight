#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    vector<P> v;
    rep(i, A) {
        int tmp;
        cin >> tmp;
        v.push_back(make_pair(tmp, 0));
    }
    rep(i, B) {
        int tmp;
        cin >> tmp;
        v.push_back(make_pair(tmp, 1));
    }
    rep(i, C) {
        int tmp;
        cin >> tmp;
        v.push_back(make_pair(tmp, 2));
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll sum = 0;
    int x = 0;
    int y = 0;
    int count = 0;
    for (int i = 0; count < (X + Y); i++) {
        if (v[i].second == 0) {
            if (x < X) {
                sum += v[i].first;
                x++;
                count++;
            }
        } else if (v[i].second == 1) {
            if (y < Y) {
                sum += v[i].first;
                y++;
                count++;
            }
        } else {
            sum += v[i].first;
            count++;
        }
    }
    cout << sum << endl;

    return 0;
}
